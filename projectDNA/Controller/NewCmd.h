//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_NEWCMD_H
#define PROJECTDNA_NEWCMD_H


#include "ICmd.h"

class NewCmd : public ICmd
{
   SharedPtr<ICmd> create();
   void help();
   void RunCmd(DnaData* data, std::vector<std::string> );
};


#endif //PROJECTDNA_NEWCMD_H
