#include <algorithm>
#include <iostream>
#include <sstream>

int main() {
    std::string name;
    std::cout << ">> ";
    std::cin >> name;
    std::string upper = name;
    std::ranges::transform(name, upper.begin(), [](auto ch) {
        if (ch == '.') ch = '_';
        return std::toupper(ch);
    });

    std::string namespace_{};
    {
        std::ostringstream ns_s{};
        for (const auto ch: name) {
            if (ch == '.') {
                ns_s << "::";
                continue;
            }
            ns_s << ch;
        }
        namespace_ = ns_s.str();
    }


    std::string macro = "INCLUDE_" + upper;

    std::cout << "----------\n";
    std::cout << "#ifndef " << macro << '\n';
    std::cout << "#define " << macro << '\n';
    std::cout << '\n' << "namespace " << namespace_ << "{\n";
    std::cout << '\n';
    std::cout << "}\n";
    std::cout << '\n';
    std::cout << "#endif//" << macro << '\n';
    std::cout << "---------\n";
}
