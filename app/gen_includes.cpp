#include <iostream>
#include <filesystem>
#include <list>
#include <fstream>

struct text_finder {
    std::string text;
    std::size_t counter;
    bool check(const char ch) {
        if (counter >= text.size())
            counter = 0;
        counter = text[counter] == ch ? counter + 1 : counter;
        return counter >= text.size();
    }
};

struct header_info {
    std::filesystem::path self;
    std::list<std::filesystem::path> dependencies;

    void append_absolute_dependency(const std::string_view path) noexcept {
        std::cout << "[INFO] adding dependency(" << path << ") to file(" << self << ")\n";
        dependencies.emplace_back(path);
    }

    void append_relative_dependency(const std::string_view path) noexcept {
        const auto dependency = self.parent_path() / path;
        std::cout << "[INFO] adding dependency(" << dependency << ") to file(" << self << ")\n";
        dependencies.emplace_back(dependency);
    }

    bool append_dependency(std::string_view include) noexcept {
        while (!include.empty() && std::isspace(include.front()))
            include.remove_prefix(1);
        while (!include.empty() && std::isspace(include.back()))
            include.remove_suffix(1);
        if (include.empty()) return false;

        if (include.front() == '<' && include.back() == '>') {
            include.remove_prefix(1);
            include.remove_suffix(1);
            append_absolute_dependency(include);
            return true;
        }

        if (include.front() == '\"' && include.back() == '\"') {
            include.remove_prefix(1);
            include.remove_suffix(1);
            append_relative_dependency(include);
            return true;
        }

        return false;
    }

    void analyze_self() noexcept {
        dependencies.clear();
        std::ifstream file_stream{self};
        if (!file_stream) {
            std::cerr << "[FATAL] cannot open target file(" << self << ") to analyze\n";
            return;
        }

        while (!file_stream.eof()) {
            std::string line{};
            std::getline(file_stream, line);

            text_finder include_finder{"#include"};
            text_finder namespace_finder{"namespace"};
            std::string_view target_line{line};
            while (!target_line.empty()) {
                const auto ch = target_line.front();
                if (include_finder.check(ch)) {
                    target_line.remove_prefix(1);
                    if (!append_dependency(target_line))
                        std::cerr << "[FATAL] cannot solve dependency line(" << line << ") at file(" << self << ")";
                    break;
                }
                if (namespace_finder.check(ch)) {
                    break;
                }
                target_line.remove_prefix(1);
            }

            if (!file_stream) {
                std::cout << "[WARN] file(" << self << ") went wrong in line getting\n";
                break;
            }
        }
    }

    void save(std::ostream& os) const noexcept {
        std::cout << "[INFO] saving file(" << self << ")\n";
        os << '[' << self << "]\n";
        for (const auto& dependency: dependencies) {
            os << " - " << dependency << '\n';
        }
    }
};

int main() {
    std::string root{};
    std::cout << ">> ";
    std::cin >> root;

    std::list<header_info> headers{};

    for (const auto& entry : std::filesystem::recursive_directory_iterator{root}) {
        if (!entry.is_regular_file() || !entry.path().extension().string().contains('h'))
            continue;

        std::cout << "[INFO] checking file(" << entry.path() << ")\n";
        header_info header{entry.path()};
        header.analyze_self();
        if (header.dependencies.empty()) continue;
        headers.emplace_back(std::move(header));
    }

    std::ofstream out{"output.txt"};
    for (const auto& header: headers) {
        header.save(out);
        out << '\n';
    }
    return 0;
}