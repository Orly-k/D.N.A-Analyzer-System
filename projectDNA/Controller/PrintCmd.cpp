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
    size_t num_char;
    std::string identifier;
    std::stringstream to_return;
//    status??

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
        return "please enter a valid sequence name or id";

   ///////////////////////take out to functions !!!!!!!!!!!!!!!!!!!!



    if(identifier == "seq_id")
    {
        std::map<size_t, SharedPtr<DnaData> >::iterator itr;
        itr = data->DnaById.find(id);
        SharedPtr<IDna> dna = itr->second->get_pdna();

        name = itr->second->getName();
        to_return<<"["<<id<<"] "<<name<<std::endl; ///status!!

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
    }
    else
    {
        std::map<std::string, SharedPtr<DnaData> >::iterator itr;
        itr = data->DnaByName.find(name);
        SharedPtr<IDna> dna = itr->second->get_pdna();

        id = itr->second->getId();
        to_return<<"["<<id<<"] "<<name<<std::endl; ///status!!

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
    }

    return to_return.str();
}