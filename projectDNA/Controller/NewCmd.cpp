//
// Created by kierszen on 12/29/18.
//

#include <sstream>
#include "NewCmd.h"
#include "../Model/DnaSequence.h"

SharedPtr<ICmd> NewCmd::create() //register
{

}

void NewCmd::help()
{
    std::cout<<"new cmd bla bla bla"<<std::endl;
}

void NewCmd::RunCmd(SharedPtr<DataCollection> data, std::vector<char*> arr)
{
    size_t vec_size = arr.size();
    bool inValidName = true;

    size_t id = data->getInc();
    std::stringstream name;

    if (vec_size < 2)
        return;

    if(vec_size == 3)
        inValidName = data->nameExists(arr[2]);

    if(inValidName)
        name<<"seq"<<id;
    else
        name<<arr[2];

    DnaData newDna(id, name.str(), SharedPtr<IDna> (new DnaSequence (arr[1])));
}

