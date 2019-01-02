//
// Created by kierszen on 12/29/18.
//

#include "LoadCmd.h"
#include "../Model/ReadDna.h"

SharedPtr<ICmd> LoadCmd::create(){}
void LoadCmd::help(){} //should return a string ??
void LoadCmd::RunCmd(SharedPtr<DataCollection> &dataCollection, std::vector<std::string> arr)
{
    size_t vec_size = arr.size();
//    size_t id = 6; //data->getInc();

    if (vec_size < 2)
        return;

    std::string name = arr[1];
    ReadDna file_dna(name);
    DnaSequence dna(file_dna.read());




}

//
//bool inValidName = true;

//std::string item;
//if(vec_size == 3)
//{
//std::stringstream ss(arr[2]);
//
//while(std::getline(ss, item, '@')){}
//
//inValidName = data->nameExists(item);
//}
//
//if(inValidName)
//{
//std::ostringstream oss;
//oss << id;
//name = "seq" + oss.str();
//}
//else
//name = item;
//
//DnaData newDna(id, name, SharedPtr<IDna> (new DnaSequence (arr[1])));
//std::cout<<"inserted to collection - id: "<<newDna.getId()<<" name: "<<newDna.getName()<<std::endl;