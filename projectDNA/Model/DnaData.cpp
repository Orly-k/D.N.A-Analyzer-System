//
// Created by kierszen on 12/29/18.
//

#include <sstream>
#include "DnaData.h"

std::string DnaData::getDescription() const
{
    std::stringstream s;
    s << "[" << m_id << "] " << m_name << ": ";
    size_t len = m_DnaSeq->get_length();
    for (size_t i=0; i<len && i<40; ++i )
    {
        s << m_DnaSeq->operator[](i);
    }
    return s.str();
}

std::map<char, std::string > DnaData::status_map = st_map_init();

std::map<char, std::string> DnaData::st_map_init()
{
    std::map<char, std::string> s;
    s.insert(std::pair<char, std::string> ('-',"up to date"));
    s.insert(std::pair<char, std::string> ('o',"new"));
    s.insert(std::pair<char, std::string> ('*',"modified"));

    return s;
}

DnaData::DnaData(size_t id, SharedPtr<IDna> DnaSeq, std::string name,  char status):m_id(id)
{
    m_DnaSeq = DnaSeq;
    m_name = name;
    m_status = status;
}




