//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_DNADATA_H
#define PROJECTDNA_DNADATA_H


#include <map>
#include "DnaData.h"



class DataCollection
{
public:
    DataCollection();

    bool nameExists(std::string name);
//    bool idExists(size_t id);

    void addDna(SharedPtr<DnaData> dna);
//    void deleteDna(std::string name);
//    void deleteDna(size_t id);
    std::string generateName(std::string name = "seq");

    size_t getInc(){ return ++inc_number; }

    std::map<std::string, SharedPtr<DnaData> > DnaByName; //moved from private!!
    std::map<size_t , SharedPtr<DnaData> >DnaById;

    std::string getAllDataDescription();

    std::string getAllDataStatus();

private:

    size_t inc_number; //static
};


#endif //PROJECTDNA_DNADATA_H
