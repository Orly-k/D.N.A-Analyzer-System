//
// Created by kierszen on 12/30/18.
//

#include "CmdFactory.h"
#include "NewCmd.h"
#include "SaveCmd.h"


SharedPtr<ICmd> CmdFactory::getCmd(std::string cmd)
{
    if (cmd == "new")
    {
        NewCmd *c = new NewCmd();
        SharedPtr<ICmd> ptr(c);

        return ptr;
    }

    if (cmd == "save")
    {
        SaveCmd *s = new SaveCmd();
        SharedPtr<ICmd> ptr(s);

        return ptr;
    }
}
