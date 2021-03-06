#include <iostream>
#include <math.h>
#include <fstream>
#include "enum.h"

#include "integer.h"
#include "string.h"
//TODO: implement control
// if VAR is 1 (number)
int UType(const std::string& c) {
    if (split(c, ' ')[0] == "if") {
        return E_IF;
    }
    else if (split(c, ' ')[0] == "else") {
        return E_ELSE;
    }
    else if (split(c, ' ')[0] == "def") {
        return E_DEF;
    }
    else if (split(c, ' ')[0] == "var") {
        return E_VAR;
    } else if (split(c, ' ')[0] == "import") {
       return E_IMPORT; 
    } 
    else if (split(c, ' ')[0] == "for") {
        return E_FOR;
    }
    else if (split(c, ' ')[0] == "while") {
        return E_WHILE;
    } else if (split(c, ' ')[0] == "return") {
        return E_RETURN;
    } else if (split(c, ' ')[0] == "array") {
        return E_BARR;
    } else if (c.find("==") != std::string::npos) {
        return E_COMP;
    }
    #ifdef USE_STACK
    else if (split(c, ' ')[0] == "stack") {
       return E_STACK; 
    } 
    #endif
    else if (c[0] == '(') {
        return E_ISO;
    } 
    else if (c.find("(") != std::string::npos)
        return E_OTHER;
    else if (c[0] == '"') {
        return E_STRING;
    } else if (IsInt(c)) {
        return E_INT;
    } else if (c[0] == '[') {
        return E_ARRAY;
    }
    // else if (IsInt(c) == false) { /* if not integer, then it's likely a var decl. */
    //     return E_LIKELY;
    // } else if (c[0] == 'e') {
        // return E_EVAL;
    else if (c[0] == '#') {
        return E_COMMENT;
    } else {
        // std::cout << "because char is " << c[0] << std::endl;
        return E_LIKELY;
    }
    
    return E_NULL;
}