#include <iostream>
#include <fstream>
#include <sstream>
const std::string SWHITESPACE = " \n\r\t\f\v";
 
std::string Cltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(SWHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string Crtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(SWHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string Ctrim(const std::string &s) {
    return Crtrim(Cltrim(s));
}


class CString {
    private:
        std::string sc;
    public:
        explicit CString(const std::string &c) {
            sc = c;
        }
        std::string Parse() {
            std::string s = Ctrim(sc);
            // std::cout << s << std::endl;
            std::string newstring;
            for (uint i = 0; i < s.length(); i++) {
                if (s[i] == '\\') {
                    switch (s[i+1]) {
                        case 'n':
                            newstring = newstring + "\n";
                            break;
                        case 't':
                            newstring = newstring + "\t";
                            break;
                        case 'r':
                            newstring = newstring + "\r";
                            break;
                        case '"':
                            newstring = newstring + "\""; /* update: add \" as escape to match other programming languages' string feature */
                            break;
                        case '(':
                            newstring = newstring + "(";
                            break;
                        
                        default: std::cout << "wrong escape sequence, '" << s[i+1] << "'" << std::endl; break;
                    }
                } else {
                    if (i != 0) {
                        if (s[i-1] != '\\') { /* not escaped */
                            newstring = newstring + s[i];
                        }
                    } else {
                        newstring = newstring + s[i];
                    }
                }
            }
            return newstring;
        }

};

std::string PrettyPrint(std::string cstring) {
    // std::cout << cstring;
    if (cstring[0] != '"' && cstring[0] != '\'') {
                std::cout << "error: cstring: 1: not a string" << std::endl;
                return "ERROR";
    }
    if (cstring[0] == '\'') {
        std::cout << "error: cstring: 1: not a string, instead character.\nDid you mean, ' \" ' ?" << std::endl;
        return "ERROR";
    }
    std::string OPEN;
    std::stringstream ss(cstring);
    std::string entstring;
    getline(ss, OPEN, '\"');
    if (cstring[cstring.length()-1] == '\'') {
        std::cout << "error: cstring: EOS: couldn't match \" with ' found at character index " << cstring.length()-1 << std::endl;
    }
    getline(ss, entstring, '\"');
    return CString(entstring).Parse();
}