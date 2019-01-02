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

void NewCmd::RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr)
{
    size_t vec_size = arr.size();
    bool inValidName = true;

    size_t id = data->getInc();

    std::string name;


    if (vec_size < 2)
        return;
    std::string item;
    if(vec_size == 3)
    {
        std::stringstream ss(arr[2]);

        while(std::getline(ss, item, '@')){}

        inValidName = data->nameExists(item);
    }

    if(inValidName)
    {
        std::ostringstream oss;
        oss << id;
        name = "seq" + oss.str();
    }
    else
        name = item;

    DnaData newDna(id, name, SharedPtr<IDna> (new DnaSequence (arr[1])));
    std::cout<<"inserted to collection - id: "<<newDna.getId()<<" name: "<<newDna.getName()<<std::endl;
}

