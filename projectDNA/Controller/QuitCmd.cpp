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
    else std::cout<<str<<"Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'."<<std::endl;
    std::cout<<"> confirm >>> ";
    std::getline(std::cin, str);

    if(str == "Y" || str == "y")
        return "quit";
    else if (str == "N" || str =="n")
        return "";
    else
        return "You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'";
}