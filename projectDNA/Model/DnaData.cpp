//
// Created by kierszen on 12/29/18.
//

#include "DnaData.h"

DnaData::DnaData(size_t id, std::string name, SharedPtr<IDna> DnaSeq, char status):m_id(id),
                                                        m_name(name), m_DnaSeq(DnaSeq), m_status(status){}



