//
// Created by kierszen on 12/29/18.
//

#include <cstring>
#include "Parser.h"

std::vector<char*> Parser::parsing(char* str)
{
    std::vector<char*> vec;

    const char s[2] = " ";
    char *token = strtok(str, s);
    vec.push_back(token);

    while( token != NULL )
    {
        token = strtok(NULL, s);
        vec.push_back(token);
    }
    return vec;
}
