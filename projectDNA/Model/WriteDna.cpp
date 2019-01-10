//
// Created by kierszen on 12/29/18.
//

#include "WriteDna.h"
#include <fstream>

using std::ofstream;

WriteDna::WriteDna(std::string FileName) :m_fileName(FileName){}


//WriteDna::WriteDna(WriteDna const & other) : m_fileName(other.m_fileName)
//{}
//
//WriteDna::~WriteDna()
//{}

void WriteDna::write(SharedPtr<IDna> dna)
{
    size_t seq_size = dna->get_length();
    ofstream myfile;
    myfile.open(m_fileName.c_str());

    if (!myfile.is_open())
        throw std::logic_error("unable to open file");

    for (size_t i = 0; i < seq_size; ++i)
    {
        myfile << dna->operator[](i);
    }

    myfile.close();
}