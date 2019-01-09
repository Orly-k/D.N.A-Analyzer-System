//
// Created by kierszen on 12/30/18.
//

#include "CmdFactory.h"
#include "NewCmd.h"
#include "SaveCmd.h"
#include "LoadCmd.h"
#include "PrintCmd.h"


SharedPtr<ICmd> CmdFactory::getCmd(std::string cmd)
{
//    if (cmd == "new")
    {
        NewCmd *c = new NewCmd();
        SharedPtr<ICmd> ptr(c);

        return ptr;
    }
//
//    if (cmd == "save")
//    {
//        SaveCmd *s = new SaveCmd();
//        SharedPtr<ICmd> ptr(s);
//
//        return ptr;
//    }
//
//    if (cmd == "load")
//    {
//        LoadCmd *l = new LoadCmd();
//        SharedPtr<ICmd> ptr(l);
//
//        return ptr;
//    }
//    if (cmd == "print")
//    {
//        PrintCmd *p = new PrintCmd();
//        SharedPtr<ICmd> ptr(p);
//
//        return ptr;
//    }
//    else /////just for compilation!!!!
//    {
//        LoadCmd *l = new LoadCmd();
//        SharedPtr<ICmd> ptr(l);
//
//        return ptr;
//    }

}
