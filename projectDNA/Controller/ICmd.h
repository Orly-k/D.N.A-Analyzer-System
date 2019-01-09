//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_ICMD_H
#define PROJECTDNA_ICMD_H

#include <string>
#include <vector>
#include "../Model/SharedPtr.h"
#include "../Model/DataCollection.h"

class ICmd
{
public:
//     virtual SharedPtr<ICmd> create() = 0;
     virtual void help() = 0;
     virtual std::string RunCmd(SharedPtr<DataCollection> &dataCollection, std::vector<std::string> ) = 0;
     virtual ~ICmd(){}
};


#endif //PROJECTDNA_ICMD_H
