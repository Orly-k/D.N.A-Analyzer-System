//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_PRINTCMD_H
#define PROJECTDNA_PRINTCMD_H


//#include <tgmath.h>
#include "ICmd.h"

class PrintCmd : public ICmd
{
public:
    SharedPtr<ICmd> create();
    void help(); //should return a string ??
    void RunCmd(SharedPtr<DataCollection> dataCollection, std::vector<std::string> arr);
};


#endif //PROJECTDNA_PRINTCMD_H
