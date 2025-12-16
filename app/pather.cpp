#include <iostream>
#include <filesystem>
#include <string>
#include <list>
#include <format>
#include <print>
#include <functional>
#include <chrono>
#include <sstream>

namespace pather {

struct context {
    std::list<std::string> parts;

    void parse(std::string_view path, const char separator) noexcept {
        parts.clear();
        while (!path.empty()) {
            const auto pos = path.find_first_of(separator);
            if (pos == std::string_view::npos) {
                parts.emplace_back(path);
                return;
            }
            parts.emplace_back(path.substr(0, pos));
            path = path.substr(pos + 1);
        }
    }

    void parse_hierarchy(const std::string_view path) noexcept {
        //parse(path, '/');
        parse(path, '\\');
    }

    void parse_plain(std::string_view path) noexcept {
        parse(path, '.');
        if (parts.size() < 2) {
            parts.clear();
            return;
        }
        const auto last = parts.back();
        parts.pop_back();
        parts.back() = std::format("{}.{}", parts.back(), last);
    }

    void write_to(std::ostream& s, const char separator) const noexcept {
        if (parts.empty()) return;
        auto cur = parts.begin();
        const auto end = parts.end();
        s << *cur++;
        while (cur != end) {
            s << separator << *cur++;
        }
    }
};

struct hierarchy_context : context {
    friend std::ostream& operator<<(std::ostream& s, const hierarchy_context& ctx) {
        ctx.write_to(s, '/');
        return s;
    }

    [[nodiscard]] std::string to_string() const noexcept {
        std::ostringstream ss{};
        ss << *this;
        return ss.str();
    }
};

struct plain_context : context {
    friend std::ostream& operator<<(std::ostream& s, const plain_context& ctx) {
        ctx.write_to(s, '.');
        return s;
    }

    [[nodiscard]] std::string to_string() const noexcept {
        std::ostringstream ss{};
        ss << *this;
        return ss.str();
    }
};

enum class mode {
    unknown,
    plain_to_hierarchy,
    hierarchy_to_plain,
};

constexpr std::string_view to_string(const mode mode) noexcept {
    switch (mode) {
    case mode::plain_to_hierarchy:
        return "p2h";
    case mode::hierarchy_to_plain:
        return "h2p";
    default:
        return "unknown";
    }
}

constexpr mode to_mode(const std::string_view str) noexcept {
    if (str == "p2h") return mode::plain_to_hierarchy;
    if (str == "h2p") return mode::hierarchy_to_plain;
    return mode::unknown;
}

using handler_t = std::function<std::filesystem::path(const std::filesystem::path&)>;

bool foreach_file(const std::filesystem::path& root, const handler_t& handler) {
    std::size_t total{0};
    std::size_t failed{0};
    std::vector<std::string> paths{};
    using clock_t = std::chrono::steady_clock;
    const auto begin = clock_t::now();
    for (const auto& entry : std::filesystem::recursive_directory_iterator(root)) {
        if (entry.is_directory()) continue;
        total += 1;
        std::println("[info] 正在处理文件：{}", entry.path().string());
        try {
            const auto transformed = handler(entry.path());
            if (transformed == entry.path().string()) continue;
            const auto parent = transformed.parent_path();
            if (!std::filesystem::exists(parent) && !std::filesystem::create_directories(parent)) {
                failed += 1;
                continue;
            }
            if (!std::filesystem::copy_file(entry.path(), transformed)) {
                failed += 1;
            }

        }
        catch (std::exception& e) {
            std::println("[warn] 在处理文件({})时发生异常：{}", entry.path().string(), e.what());
            failed += 1;
        }
    }
    const auto end = clock_t::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::println("[info] 处理了{}个文件，其中{}个文件处理失败，共耗时{}ms", total, failed, duration.count());
    return failed == 0;
}

bool plain2hierarchy(const std::filesystem::path& root) noexcept {
    const auto handler = [root](const std::filesystem::path& path) {
        hierarchy_context context{};
        const auto relative_path = std::filesystem::relative(path, root);
        context.parse_plain(relative_path.string());
        return root/context.to_string();
    };
    return foreach_file(root, handler);
}

bool hierarchy2plain(const std::filesystem::path& root) noexcept {
    const auto handler = [root](const std::filesystem::path& path) {
        plain_context context{};
        const auto relative_path = std::filesystem::relative(path, root);
        context.parse_hierarchy(relative_path.string());
        return root/context.to_string();
    };
    return foreach_file(root, handler);
}

}

using namespace pather;

int main(const int argc, const char* argv[]) {
    //pather p2h|h2p <root>
    if (argc < 3) {
        if (argc == 0) return 0;
        std::println(std::cerr, "使用方式：\n{} p2h|h2p <dir>", argv[0]);
        return 0;
    }
    const auto mode = to_mode(argv[1]);
    std::filesystem::path root {argv[2]};
    switch (mode) {
    case mode::plain_to_hierarchy:
        return plain2hierarchy(root) ? 0 : 1;

    case mode::hierarchy_to_plain:
        return hierarchy2plain(root) ? 0 : 1;
    default:
        std::println(std::cerr, "未知的模式");
        return 1;
    }
}
