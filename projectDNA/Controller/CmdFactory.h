//
// Created by kierszen on 12/30/18.
//

#ifndef PROJECTDNA_CMDFACTORY_H
#define PROJECTDNA_CMDFACTORY_H

#include <map>
#include <string>
#include <vector>
#include "ICmd.h"

using std::string;

class CmdFactory
{

public:
    static std::map<string,SharedPtr<ICmd> > CmdMap;
//    static void registerToFactory(std::string cmd, );

    static SharedPtr<ICmd> getCmd(string cmd);

};


#endif //PROJECTDNA_CMDFACTORY_H
