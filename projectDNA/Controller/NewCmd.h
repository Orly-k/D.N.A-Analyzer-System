//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_NEWCMD_H
#define PROJECTDNA_NEWCMD_H


#include "ICmd.h"

class NewCmd : public ICmd
{
public:
   SharedPtr<ICmd> create();
   void help(); //should return a string ??
   void RunCmd(DnaData* data, std::vector<std::string> );

private:
//    static bool

};


#endif //PROJECTDNA_NEWCMD_H
