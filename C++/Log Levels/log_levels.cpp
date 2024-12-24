#include <string>
#include <cctype>

namespace log_line {
    std::string message(std::string line) {
        size_t pos = line.find("]: ");
        return line.substr(pos + 3);
    }

    std::string log_level(std::string line) {
        size_t start = line.find("[") + 1, end = line.find("]");
        return line.substr(start, end - start);
    }

    std::string reformat(std::string line) {
        std::string msg = message(line);
        std::string level = log_level(line);
        return msg + " (" + level + ")";
    }
}
