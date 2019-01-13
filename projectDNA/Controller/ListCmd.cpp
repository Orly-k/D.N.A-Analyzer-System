//
// Created by kierszen on 1/12/19.
//

#include "ListCmd.h"
#include "CmdFactory.h"

bool ListCmd::reg = CmdFactory::getInstance()->registerToFactory("list", SharedPtr<ICmd> (new ListCmd));

void ListCmd::help(){std::cout<<"list";}//should return a string ??

std::string ListCmd::RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr)
{
    if(arr.size() != 1)
        return "invalid arguments for command list";
    return data->getAllDataDescription();
}