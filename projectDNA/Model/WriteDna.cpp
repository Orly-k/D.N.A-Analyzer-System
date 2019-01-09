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

void WriteDna::write(DnaSequence dna)
{
    ofstream myfile;
    myfile.open(m_fileName.c_str());

    if (!myfile.is_open())
        throw std::logic_error("unable to open file");

    myfile << dna.get_m_seq();
    myfile.close();
}