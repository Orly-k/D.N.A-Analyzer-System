//
// Created by kierszen on 12/29/18.
//

#include <sstream>
#include "LoadCmd.h"
#include "../Model/ReadDna.h"

//SharedPtr<ICmd> LoadCmd::create(){}
void LoadCmd::help(){} //should return a string ??


std::string LoadCmd::RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr)
{
    size_t vec_size = arr.size();
    size_t id = data->getInc();
    std::string filename = arr[1];
    std::string name;
    std::stringstream to_return;

    if (vec_size != 2 && vec_size != 3)
        return "This Command requires 2 or 3 arguments!\n";

    std::size_t pos = filename.find(".rawdna");
    if (pos == std::string::npos)
        return "invalid file!\n";

    ReadDna file_dna(filename);
    DnaSequence dna(file_dna.read());

    if(vec_size == 3)
    {
        if (arr[2][0] != '@')
            return "invalid sequence name!\n";

        std::stringstream ss(arr[2]);
        while(std::getline(ss, name, '@')){}
        name = data->generateName(name);
    }
    else
    {
        std::string onlyName = filename.erase (pos);

        name = data->generateName(onlyName);
    }

    SharedPtr<IDna> pdna(new DnaSequence(dna));
    SharedPtr<DnaData> pnewDna(new DnaData(id, pdna, name));
    data->addDna(pnewDna);

    size_t seqSize = pdna->get_length();
    std::stringstream str;
    if (seqSize > 40)
    {

        for (size_t i = 0; i < 32; ++i)
        {
            str<<pdna->operator[](i);
        }
        str<<"...";
        for (size_t j = (seqSize - 3); j < seqSize; ++j)
        {
            str<<pdna->operator[](j);
        }
    }
    else
    {
        for (size_t i = 0; i < seqSize; ++i)
        {
            str<<pdna->operator[](i);
        }
    }

    to_return<<"["<<pnewDna->getId()<<"] "<<pnewDna->getName()<<": "<<str.str()<<std::endl;

    return to_return.str();
}

