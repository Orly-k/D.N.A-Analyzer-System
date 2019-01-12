//
// Created by kierszen on 12/29/18.
//

#include <sstream>
#include "ShowCmd.h"

//SharedPtr<ICmd> ShowCmd::create() //register
//{
//
//}

void ShowCmd::help()
{
    std::cout<<"print cmd bla bla bla"<<std::endl;
}

std::string ShowCmd::RunCmd(SharedPtr<DataCollection> &data, std::vector<std::string> arr)
{
    size_t vec_size = arr.size();
    size_t num_char;
    std::string identifier;
    std::stringstream to_return;
    char status;

    if (vec_size != 2 && vec_size != 3)
        return "This Command requires 2 or 3 arguments!\n";


    std::string name = " ";
    size_t id = 0;

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
        return "please enter a valid sequence name or id\n";

   ///////////////////////take out to functions !!!!!!!!!!!!!!!!!!!!


    SharedPtr<IDna> dna;
    if(identifier == "seq_id")
    {
        std::map<size_t, SharedPtr<DnaData> >::iterator itr;
        itr = data->DnaById.find(id);
        dna = itr->second->get_pdna();
        status = itr->second->get_status();
        std::map<char, std::string> ::iterator stat_itr;
        stat_itr = itr->second->status_map.find(status);
        std::string mystat = stat_itr->second;
        name = itr->second->getName();
        to_return << "[" << id << "] " << name <<" "<<mystat<<std::endl;
    }
    else
    {
        std::map<std::string, SharedPtr<DnaData> >::iterator itr;
        itr = data->DnaByName.find(name);
        dna = itr->second->get_pdna();
        status = itr->second->get_status();
        std::map<char, std::string> ::iterator stat_itr;
        stat_itr = itr->second->status_map.find(status);
        std::string mystat = stat_itr->second;
        id = itr->second->getId();
        to_return<<"["<<id<<"] "<<name<<" "<<mystat<<std::endl;
    }

    size_t seq_size = dna->get_length();
    if (vec_size == 3)
    {
        std::istringstream chars(arr[2]);
        chars >> num_char;
    }
    else if (seq_size >= 99) ///use 99 as defined
        num_char = 99;
    else
        num_char = seq_size;

    for (size_t i = 0; i < num_char; ++i)
    {
        to_return<<dna->operator[](i);

        if(i % 98 == 0 && i != 0)
            to_return<<std::endl;
    }
    to_return<<std::endl;
    return to_return.str();
}