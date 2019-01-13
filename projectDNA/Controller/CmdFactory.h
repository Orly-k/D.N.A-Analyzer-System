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
    static CmdFactory* getInstance();

    bool registerToFactory(std::string cmdName, SharedPtr<ICmd> cmd);
    SharedPtr<ICmd> getCmd(string cmd);

private:
    CmdFactory();
    static CmdFactory* instance;

    std::map<string,SharedPtr<ICmd> > CmdMap;
};


#endif //PROJECTDNA_CMDFACTORY_H
