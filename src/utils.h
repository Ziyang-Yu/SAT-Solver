#include <algorithm> 
#include <cctype>
#include <locale>

#include <iostream>
#include <string>
#include <algorithm>
 

using namespace std;

// trim from start (in place)
// std::string ltrim(std::string s);
std::string ltrim(const std::string &s);
// trim from end (in place)
std::string rtrim(const std::string &s);
// std::string rtrim(std::string s);

// trim from both ends (in place)
std::string trim(std::string s);

bool is_number(string str);