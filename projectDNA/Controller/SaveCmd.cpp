//
// Created by kierszen on 12/29/18.
//

#include <sstream>
//#include <unistd.h>
#include "SaveCmd.h"
#include "../Model/WriteDna.h"

//SharedPtr<ICmd> SaveCmd::create(){}

void SaveCmd::help(){}//should return a string ??

std::string SaveCmd::RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr)
{
    size_t vec_size = arr.size();
//    size_t id = data->getInc();
    std::stringstream file_name;

    if (vec_size != 2 && vec_size != 3)
        return "This Command requires 2 or 3 arguments!\n";

    std::string name = data->generateName("seq");

    if(vec_size == 2)
        file_name<<name;
    else
        file_name<<arr[2];

    file_name<<".rawdna";

    WriteDna s(file_name.str());
    DnaSequence dna(arr[1]);
    s.write(dna);

    return "dd\n";
}
