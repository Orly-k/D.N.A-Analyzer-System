//
// Created by kierszen on 12/29/18.
//

#include "NewCmd.h"

SharedPtr<ICmd> NewCmd::create()
{

}

void NewCmd::help()
{
    std::cout<<"new cmd bla bla bla"<<std::endl;
}

void NewCmd::RunCmd(DnaData* data, std::vector<std::string> )
{

}