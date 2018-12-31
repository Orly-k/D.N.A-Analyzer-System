//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_DNAEXECUTE_H
#define PROJECTDNA_DNAEXECUTE_H

#include "../Model/DataCollection.h"
#include "../View/Parser.h"
#include "../View/CLI.h"

class Execute
{
public:
    void run();

private:
    SharedPtr<DnaData> data;
    CLI cli;
    char* s;
    Parser p;
    std::vector<char*> arr;

};


#endif //PROJECTDNA_DNAEXECUTE_H
