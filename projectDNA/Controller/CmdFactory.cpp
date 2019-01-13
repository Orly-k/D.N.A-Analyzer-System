//
// Created by kierszen on 12/30/18.
//

#include "CmdFactory.h"

bool CmdFactory::registerToFactory(std::string cmdName, SharedPtr<ICmd> cmd)
{
    CmdMap[cmdName] = cmd;
    return true;
}

CmdFactory* CmdFactory::instance = 0;

CmdFactory* CmdFactory::getInstance()
{
    if (instance == 0)
    {
        instance = new CmdFactory();
    }

    return instance;
}

CmdFactory::CmdFactory(){}


SharedPtr<ICmd> CmdFactory::getCmd(std::string cmd)
{
    return CmdMap[cmd];
}
