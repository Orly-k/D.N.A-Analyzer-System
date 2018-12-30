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
    bool nameExists(std::string name);
    bool idExists(size_t id);

    void addDna(SharedPtr<DnaData>);
    void deleteDna(std::string name);
    void deleteDna(size_t id);

private:
    static std::map<std::string, SharedPtr<DnaData> > DnaByName;
    static std::map<size_t , SharedPtr<DnaData> >DnaById;
};


#endif //PROJECTDNA_DNADATA_H
