//
// Created by kierszen on 12/29/18.
//

#include <sstream>
#include <unistd.h>
#include "SaveCmd.h"
#include "../Model/WriteDna.h"

SharedPtr<ICmd> SaveCmd::create(){}
void SaveCmd::help(){}//should return a string ??

void SaveCmd::RunCmd(SharedPtr<DataCollection> data, std::vector<std::string> arr)
{
    size_t vec_size = arr.size();
    bool inValidName = true;
    size_t id = 3; // data->getInc();
    std::string name;

    if (vec_size < 2)
        return;
    if(vec_size == 3)
        inValidName = data->nameExists(arr[2]);
    if(inValidName)
    {
        std::ostringstream oss;
        oss<<id;
        name = "seq" + oss.str();
    }
    else
        name = arr[2];

    WriteDna s(name);

    DnaSequence dna(arr[1]);

    s.write(dna);
}
