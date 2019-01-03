//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_READDNA_H
#define PROJECTDNA_READDNA_H


#include "DnaSequence.h"

class ReadDna
{
public:
    ReadDna(const std::string &FileName);
//    ReadDna(ReadDna const &other);
//    ~ReadDna();
    DnaSequence read();
private:
    std::string m_fileData;
};


#endif //PROJECTDNA_READDNA_H
