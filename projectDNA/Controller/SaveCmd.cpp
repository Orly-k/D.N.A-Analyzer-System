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
    std::string identifier;
    std::stringstream file_name;
    size_t id = 0;
    std::string name;
    std::stringstream to_return;

    if (vec_size != 2 && vec_size != 3)
        return "This Command requires 2 or 3 arguments!\n";


    if (arr[1][0]=='#')
    {
        identifier = "seq_id";

        std::string seq_id;
        std::stringstream ss(arr[1]);
        while(std::getline(ss, seq_id, '#')){}

        std::istringstream iss(seq_id);
        iss >> id;
    }

    else if (arr[1][0]=='@')
    {
        identifier = "seq_name";

        std::stringstream ss(arr[1]);
        while(std::getline(ss, name, '@')){}
    }
    else
        return "please enter a valid sequence name or id";

    SharedPtr<IDna> dna;
    if(identifier == "seq_id")
    {
        std::map<size_t, SharedPtr<DnaData> >::iterator itr;
        itr = data->DnaById.find(id);
        dna = itr->second->get_pdna();
        name = itr->second->getName();
    }
    else
    {
        std::map<std::string, SharedPtr<DnaData> >::iterator itr;
        itr = data->DnaByName.find(name);
        dna = itr->second->get_pdna();
        id = itr->second->getId();
    }


    if (vec_size == 3)
        file_name<<arr[2];
    else
        file_name<<name;
    file_name<<".rawdna";

    WriteDna s(file_name.str());
    s.write(dna);

    return to_return.str();
}


