//
// Created by kierszen on 12/29/18.
//

#include "QuitCmd.h"

void QuitCmd::help(){std::cout<<"bla";} //should return a string ??

std::string QuitCmd::RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr)
{
    return "quit";
}