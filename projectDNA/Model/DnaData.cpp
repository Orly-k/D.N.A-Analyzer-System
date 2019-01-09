//
// Created by kierszen on 12/29/18.
//

#include "DnaData.h"

DnaData::DnaData(size_t id, SharedPtr<IDna> DnaSeq, std::string name,  char status):m_id(id)
{
    m_DnaSeq = DnaSeq;
    m_name = name;
    m_status = status;
}




