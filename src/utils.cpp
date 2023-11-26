
#include "utils.h"

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

// trim from both ends (in place)
std::string trim(std::string s) {
    s = rtrim(s);
    s = ltrim(s);
    return s;
}

bool is_number(string str)
{
    for (char ch : str) {
        // cout << "ch:" << ch << endl;
        int v = ch; // ASCII Val converted
        if (!(ch >= 48 && ch <= 57)) {
            return false;
        }
    }
 
    return true;
}