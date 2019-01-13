//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_EXITCMD_H
#define PROJECTDNA_EXITCMD_H


#include "ICmd.h"

class QuitCmd : public ICmd
{
//    SharedPtr<ICmd> create();
    void help(); //should return a string ??
    std::string RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr);

private:
    static bool reg;
};


#endif //PROJECTDNA_EXITCMD_H
