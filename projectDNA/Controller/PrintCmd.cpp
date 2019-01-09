//
// Created by kierszen on 12/29/18.
//

#include <sstream>
#include "PrintCmd.h"

//SharedPtr<ICmd> PrintCmd::create() //register
//{
//
//}

void PrintCmd::help()
{
    std::cout<<"print cmd bla bla bla"<<std::endl;
}

std::string PrintCmd::RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr)
{
    size_t vec_size = arr.size();
    size_t num_of_chars;

    if (vec_size < 2)
        return "dd";

    if(vec_size == 2)
        num_of_chars = 99;

    else if(vec_size == 3)
    {
        std::istringstream iss(arr[2]);
        iss >> num_of_chars;
    }

    std::string seq_id;
    std::stringstream ss(arr[1]);
    while(std::getline(ss, seq_id, '#')){}

    size_t id;
    std::istringstream isss(seq_id);
    isss >> id;

    std::map<size_t, SharedPtr<DnaData> >::iterator itr;

    itr = data->DnaById.find(id);
    std::string name = itr->second->getName();

    std::cout<<"seq_name by id 1 suppose seq1: "<<name<<std::endl;

    return "dd";
}