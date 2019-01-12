//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_PRINTCMD_H
#define PROJECTDNA_PRINTCMD_H


//#include <tgmath.h>
#include "ICmd.h"

class ShowCmd : public ICmd
{
public:
//    SharedPtr<ICmd> create();
    void help(); //should return a string ??
    std::string RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr);
};


#endif //PROJECTDNA_PRINTCMD_H
