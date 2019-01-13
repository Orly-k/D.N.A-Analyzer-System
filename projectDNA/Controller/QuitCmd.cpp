//
// Created by kierszen on 12/29/18.
//

#include "QuitCmd.h"
#include "CmdFactory.h"

bool QuitCmd::reg = CmdFactory::getInstance()->registerToFactory("quit", SharedPtr<ICmd> (new QuitCmd));

void QuitCmd::help(){std::cout<<"bla";} //should return a string ??

std::string QuitCmd::RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr)
{
    std::string str = data->getAllDataStatus();
    if (str == "updated")
        return "quit";
    else return str;
}