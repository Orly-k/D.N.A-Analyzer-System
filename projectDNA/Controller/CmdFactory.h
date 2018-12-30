//
// Created by kierszen on 12/30/18.
//

#ifndef PROJECTDNA_CMDFACTORY_H
#define PROJECTDNA_CMDFACTORY_H

#include <map>
#include <string>
#include <vector>

using std::string;

class CmdFactory
{

public:
    static std::map<string,std::vector<string> > CmdMap;
};


#endif //PROJECTDNA_CMDFACTORY_H
