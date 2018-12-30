//
// Created by kierszen on 12/29/18.
//

#ifndef PROJECTDNA_WRITETOFILE_H
#define PROJECTDNA_WRITETOFILE_H


#include "DnaSequence.h"

class WriteDna
{
public:
    WriteDna(const char *FileName);
    void write(const DnaSequence);

private:
    const char* FileName;
//    std::
//    - m_outfile: ofstream

};

//    WriteFile(WriteFile const & other);
//    ~WriteFile();



#endif //PROJECTDNA_WRITETOFILE_H
