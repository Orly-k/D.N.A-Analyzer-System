//
// Created by kierszen on 1/12/19.
//

#include "ListCmd.h"

void ListCmd::help(){std::cout<<"list";}//should return a string ??
std::string ListCmd::RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr)
{
    return data->getAllDataDescription();
}