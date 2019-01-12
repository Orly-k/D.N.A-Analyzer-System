//
// Created by kierszen on 12/30/18.
//

#include "CmdFactory.h"
#include "NewCmd.h"
#include "SaveCmd.h"
#include "LoadCmd.h"
#include "ShowCmd.h"
#include "QuitCmd.h"
#include "ListCmd.h"

//std::map<string,SharedPtr<ICmd> > CmdFactory::CmdMap = CmdMap_init();

//std::map<string,SharedPtr<ICmd> > CmdFactory::CmdMap_init()
//{
//    std::map<string,SharedPtr<ICmd> > mymap;
//    return mymap;
//}
//
//bool CmdFactory::registerToFactory(std::string cmdName, SharedPtr<ICmd>(*create)())
//{
//    CmdMap[cmdName] = create();
//    return true;
//}
//

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

    if (cmd == "load")
    {
        LoadCmd *l = new LoadCmd();
        SharedPtr<ICmd> ptr(l);

        return ptr;
    }
    if (cmd == "show")
    {
        ShowCmd *p = new ShowCmd();
        SharedPtr<ICmd> ptr(p);

        return ptr;
    }
    if (cmd == "quit")
    {
        QuitCmd *p = new QuitCmd();
        SharedPtr<ICmd> ptr(p);

        return ptr;
    }
    if (cmd == "list")
    {
        ListCmd *p = new ListCmd();
        SharedPtr<ICmd> ptr(p);

        return ptr;
    }
    else /////just for compilation!!!!
    {
        LoadCmd *l = new LoadCmd();
        SharedPtr<ICmd> ptr(l);

        return ptr;
    }

}
