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
        name = "seq"; ///extra cus gets by default?

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

std::string DataCollection::getAllDataDescription()
{
    std::map<size_t , SharedPtr<DnaData> >::iterator itr;
    std::stringstream str;

    for (itr = DnaById.begin(); itr != DnaById.end(); ++itr)
    {
        str << itr->second->get_status()<<" ";
        str << itr->second->getDescription() << std::endl;
    }
    return str.str();
}

std::string DataCollection::getAllDataStatus()
{
    std::map<size_t , SharedPtr<DnaData> >::iterator itr;
    size_t new_counter = 0;
    size_t modified_counter = 0;
    std::stringstream str;

    for (itr = DnaById.begin(); itr != DnaById.end(); ++itr)
    {
        if (itr->second->get_status() == 'o')
            new_counter++;

        if (itr->second->get_status() == '*')
            modified_counter++;
    }
    if (new_counter != 0 && modified_counter != 0)
        str<<"There are "<<modified_counter<<" modified and "<<new_counter<<" new sequences. Are you sure you want to quit?"<<std::endl;
    else if (new_counter != 0)
        str<<"There are "<<new_counter<<" new sequences. Are you sure you want to quit?"<<std::endl;
    else if (modified_counter != 0)
        str<<"There are "<<modified_counter<<" modified sequences. Are you sure you want to quit?"<<std::endl;
    else
        str<<"updated";

    return str.str();
}