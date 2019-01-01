//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_WRITETOFILE_H
#define PROJECTDNA_WRITETOFILE_H


#include <sstream>
#include "DnaSequence.h"

class WriteDna
{
public:
    WriteDna(std::string FileName);
    //WriteDna(WriteFile const & other); ?
    //    ~WriteFile();
    void write(DnaSequence dna);

private:
    std::string m_fileName;
};
#endif //PROJECTDNA_WRITETOFILE_H

