//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_SAVECMD_H
#define PROJECTDNA_SAVECMD_H


#include "ICmd.h"

class SaveCmd: public ICmd
{
public:
    SharedPtr<ICmd> create();
    void help(); //should return a string ??
    void RunCmd(SharedPtr<DataCollection> data, std::vector<std::string> arr);
};


#endif //PROJECTDNA_SAVECMD_H
