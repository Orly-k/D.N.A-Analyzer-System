//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_NEWCMD_H
#define PROJECTDNA_NEWCMD_H


#include "ICmd.h"
#include "CmdFactory.h"

class NewCmd : public ICmd
{
public:
   void help(); //should return a string ??
    std::string RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr);

private:
    static bool reg;

};


#endif //PROJECTDNA_NEWCMD_H
