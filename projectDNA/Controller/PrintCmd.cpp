//
// Created by kierszen on 12/29/18.
//

#include "PrintCmd.h"

SharedPtr<ICmd> PrintCmd::create() //register
{

}

void PrintCmd::help()
{
    std::cout<<"print cmd bla bla bla"<<std::endl;
}

void PrintCmd::RunCmd(SharedPtr<DataCollection> data, std::vector<std::string> arr)
{

}