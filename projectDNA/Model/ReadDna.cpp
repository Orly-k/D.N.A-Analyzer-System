//
// Created by kierszen on 12/29/18.
//

#include "ReadDna.h"

#include <fstream>
using std::ifstream;

ReadDna::ReadDna(const std::string FileName)
{
    std::ifstream myfile(FileName.c_str());
    if (!myfile.is_open())
        throw std::logic_error("unable to open file");

    while (!myfile.eof())
    {
        myfile >> m_fileData;
    }
    myfile.close();
}

//ReadDna::ReadDna(ReadDna const &other) :m_fileData(other.m_fileData){}

//ReadDna::~ReadDna(){}

DnaSequence ReadDna::read()
{
    DnaSequence Dna(m_fileData);
    return Dna;
}