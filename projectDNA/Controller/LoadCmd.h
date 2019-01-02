//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_LOADCMD_H
#define PROJECTDNA_LOADCMD_H


#include "ICmd.h"

class LoadCmd: public ICmd
{
public:
    SharedPtr<ICmd> create();
    void help(); //should return a string ??
    void RunCmd(SharedPtr<DataCollection> &dataCollection, std::vector<std::string> arr);

};


#endif //PROJECTDNA_LOADCMD_H
