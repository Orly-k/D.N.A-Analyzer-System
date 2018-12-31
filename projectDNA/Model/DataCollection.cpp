//
// Created by kierszen on 12/29/18.
//

#include "DataCollection.h"

DataCollection::DataCollection()
{
    inc_number = 0;
}

bool DataCollection::nameExists(std::string name)
{
    std::map<std::string, SharedPtr<DnaData> >::iterator itr;

    for (itr = DnaByName.begin(); itr != DnaByName.end(); ++itr)
    {
        if (itr->first != name)
            return true;
    }
    return false;
}

bool DataCollection::idExists(size_t id)
{
    std::map<size_t, SharedPtr<DnaData> >::iterator itr;

    for (itr = DnaById.begin(); itr != DnaById.end(); ++itr)
    {
        if (itr->first != id)
            return true;
    }
    return false;
}

void DataCollection::addDna(SharedPtr<DnaData> dna)
{
    inc_number++;

    DnaByName.insert(std::pair<std::string, SharedPtr<DnaData> >(dna->getName(), dna) );
    DnaById.insert(std::pair<size_t , SharedPtr<DnaData> >(dna->getId(), dna) );
}

void DataCollection::deleteDna(std::string name)
{
    size_t dna_id;

    std::map<size_t, SharedPtr<DnaData> >::iterator itr;

//    itr = DnaByName.find(name);

    for (itr = DnaById.begin(); itr != DnaById.end(); ++itr)
    {
//        if (itr->second == DnaByName(name))
            dna_id = itr->first;
    }

    DnaByName.erase(name);
//    DnaById.erase(dna_id);
}

void DataCollection::deleteDna(size_t id)
{
    std::string name;
    std::map<std::string, SharedPtr<DnaData> >::iterator itr;

    for (itr = DnaByName.begin(); itr != DnaByName.end(); ++itr)
    {
//        if (itr->second == DnaById(id))
            name = itr->first;
    }

    DnaById.erase(id);
    DnaByName.erase(name);

}