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
//    SharedPtr<CLICmd> getCliToRun(string cmd):
//    void runCmd(SharedPtr<CLICmd>>, vector);

    void ex();

private:
//    DnaData* data;
    CLI cli;
    std::string s;
    Parser p;
    std::vector<std::string> arr;

};


#endif //PROJECTDNA_DNAEXECUTE_H
