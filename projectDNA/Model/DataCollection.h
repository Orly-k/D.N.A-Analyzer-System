//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_DNADATA_H
#define PROJECTDNA_DNADATA_H


#include <string>
#include <map>
#include "DnaData.h"

class DataCollection
{
public:
    DataCollection();

    bool nameExists(std::string name);
    bool idExists(size_t id);

    void addDna(SharedPtr<DnaData> dna);
    void deleteDna(std::string name);
    void deleteDna(size_t id);

    size_t getInc(){ return inc_number; }

private:
    std::map<std::string, SharedPtr<DnaData> > DnaByName;
    std::map<size_t , SharedPtr<DnaData> >DnaById;

    size_t inc_number;
};



#endif //PROJECTDNA_DNADATA_H
