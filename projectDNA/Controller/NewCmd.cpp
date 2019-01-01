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

void NewCmd::RunCmd(SharedPtr<DataCollection> data, std::vector<std::string> arr)
{
    size_t vec_size = arr.size();
    bool inValidName = true;

    size_t id = 5; // data->getInc();
//    std::stringstream name;
    std::string name;

    if (vec_size < 2)
        return;

    if(vec_size == 3)
        inValidName = data->nameExists(arr[2]);

    if(inValidName)
    {
        std::ostringstream oss;
        oss << id;
        name = "seq_" + oss.str();
    }
    else
        name = arr[2];

    DnaData newDna(id, name, SharedPtr<IDna> (new DnaSequence (arr[1])));
    std::cout<<"inserted to collection - id: "<<newDna.getId()<<" name: "<<newDna.getName()<<std::endl;
}

