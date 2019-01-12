//
// Created by kierszen on 12/30/18.
//

#ifndef PROJECTDNA_CMDFACTORY_H
#define PROJECTDNA_CMDFACTORY_H

#include <map>
#include "ICmd.h"

using std::string;

class CmdFactory
{

public:
//    static bool registerToFactory(std::string cmdName, SharedPtr<ICmd>(*create)());
    static SharedPtr<ICmd> getCmd(string cmd);

private:
//    static std::map<string,SharedPtr<ICmd> > CmdMap;
//    static std::map<string,SharedPtr<ICmd> > CmdMap_init();
};


#endif //PROJECTDNA_CMDFACTORY_H
