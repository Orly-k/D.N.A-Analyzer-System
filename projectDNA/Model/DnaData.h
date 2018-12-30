//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_DNAMETADATA_H
#define PROJECTDNA_DNAMETADATA_H


#include <cstdio>
#include <string>
#include "../Model/SharedPtr.h"
#include "IDna.h"

class DnaData
{
public:
    std::string getName(){ return this->m_name;}
    size_t getId(){ return this->m_id;}
private:
    size_t m_id;
    std::string m_name;
    char m_status;
    SharedPtr<IDna*> m_DnaSeq;
};


#endif //PROJECTDNA_DNAMETADATA_H
