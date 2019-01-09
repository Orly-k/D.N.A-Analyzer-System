//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_DNAMETADATA_H
#define PROJECTDNA_DNAMETADATA_H


#include <cstdio>
#include "IDna.h"

class DnaData
{
public:
    DnaData(size_t id, SharedPtr<IDna> DnaSeq, std::string name,  char status = 'o');
    std::string getName(){ return this->m_name;}
    size_t getId(){ return this->m_id;}

//    op== ??

private:
    size_t m_id;
    std::string m_name;
    char m_status;
    SharedPtr<IDna> m_DnaSeq;
};


#endif //PROJECTDNA_DNAMETADATA_H
