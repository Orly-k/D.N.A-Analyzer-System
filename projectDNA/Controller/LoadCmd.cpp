//
// Created by kierszen on 12/29/18.
//

#include <sstream>
#include "LoadCmd.h"
#include "../Model/ReadDna.h"

SharedPtr<ICmd> LoadCmd::create(){}
void LoadCmd::help(){} //should return a string ??

void LoadCmd::RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr)
{
    size_t vec_size = arr.size();
    size_t id = data->getInc();
    std::string filename = arr[1];
    std::string name;

    if (vec_size < 2)
        return;

    ReadDna file_dna(filename);
//    DnaSequence dna;
    DnaSequence dna(file_dna.read());

    if(vec_size == 3)
    {
        std::stringstream ss(arr[2]);
        while(std::getline(ss, name, '@')){}
        name = data->generateName(name);

    }
    else
    {
        std::size_t pos = filename.find(".rawdna");
        std::string onlyName = filename.erase (pos);

        name = data->generateName(onlyName);
    }

    SharedPtr<IDna> pdna(new DnaSequence(dna));

    DnaData newDna(id, name, pdna);
    std::cout<<"inserted to collection from file! id: "<<newDna.getId()<<" name: "<<newDna.getName()<<std::endl;
}

