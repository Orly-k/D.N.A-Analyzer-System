//
// Created by kierszen on 12/29/18.
//

#include <sstream>
#include "DataCollection.h"

DataCollection::DataCollection()
{
    inc_number = 0;
}

bool DataCollection::nameExists(std::string name)
{
    std::map<std::string, SharedPtr<DnaData> >::iterator itr;
//
////    itr = DnaByName.find(name);
//
//    for (itr = DnaByName.begin(); itr != DnaByName.end(); ++itr)
//    {
//        if (itr->first == name)
//        std::cout<<itr->first<<std::endl;
//            return true;
//    }
//
////    if (itr != DnaByName.end())
////        return true;
//    return false;

    return DnaByName.count(name) ? true:false;
}

//bool DataCollection::idExists(size_t id)
//{
//    std::map<size_t, SharedPtr<DnaData> >::iterator itr;
//
//    for (itr = DnaById.begin(); itr != DnaById.end(); ++itr)
//    {
//        if (itr->first != id)
//            return true;
//    }
//    return false;
//}

void DataCollection::addDna(SharedPtr<DnaData> dna)
{

    DnaByName.insert(std::pair<std::string, SharedPtr<DnaData> >(dna->getName(), dna) );
    DnaById.insert(std::pair<size_t , SharedPtr<DnaData> >(dna->getId(), dna) );
}

//void DataCollection::deleteDna(std::string name)
//{
//    size_t dna_id;
//
//    std::map<size_t, SharedPtr<DnaData> >::iterator itr;
//
////    itr = DnaByName.find(name);
//
//    for (itr = DnaById.begin(); itr != DnaById.end(); ++itr)
//    {
////        if (itr->second == DnaByName(name))
//            dna_id = itr->first;
//    }
//
//    DnaByName.erase(name);
////    DnaById.erase(dna_id);
//}
//
//void DataCollection::deleteDna(size_t id)
//{
//    std::string name;
//    std::map<std::string, SharedPtr<DnaData> >::iterator itr;
//
//    for (itr = DnaByName.begin(); itr != DnaByName.end(); ++itr)
//    {
////        if (itr->second == DnaById(id))
//            name = itr->first;
//    }
//
//    DnaById.erase(id);
//    DnaByName.erase(name);
//
//}


std::string DataCollection::generateName(std::string name)
{
    if (name.empty())
        name = "seq";

    if(!(nameExists(name)) && (name !="seq"))
        return name;

    size_t n = 1;
    std::stringstream s;
    s << name << n;
    while(nameExists(s.str()))
    {
        s.str("");
        s << name << ++n;
    }
    return s.str();
}