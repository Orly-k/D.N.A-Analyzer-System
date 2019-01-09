//
// Created by kierszen on 12/29/18.
//

#include <sstream>
#include "Parser.h"

//std::vector<char*> Parser::parsing(char* str)
//{
//    std::vector<char*> vec;
//
//    const char s[2] = " ";
//    char *token = strtok(str, s);
//    vec.push_back(token);
//
//    while( token != NULL )
//    {
//        token = strtok(NULL, s);
//        vec.push_back(token);
//    }
//    return vec;
//}

std::vector<std::string> Parser::parsing(std::string str)
{
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> elems;
    while(std::getline(ss, item, ' '))
    {
        elems.push_back(item);
    }
    return elems;
}
