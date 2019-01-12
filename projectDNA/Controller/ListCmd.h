//
// Created by kierszen on 1/12/19.
//

#ifndef PROJECTDNA_LISTCMD_H
#define PROJECTDNA_LISTCMD_H


#include "ICmd.h"

class ListCmd : public ICmd
{
public:
//   static SharedPtr<ICmd> create();
    void help(); //should return a string ??
    std::string RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr);

private:
//    static bool reg;


};


#endif //PROJECTDNA_LISTCMD_H
