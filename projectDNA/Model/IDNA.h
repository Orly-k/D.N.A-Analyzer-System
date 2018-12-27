//
// Created by kierszen on 12/27/18.
//

#ifndef PROJECTDNA_IDNA_H
#define PROJECTDNA_IDNA_H

#include "Nucleotide.h"

class IDNA
{
public:
    virtual Nucleotide& operator [] (size_t indx) = 0;
    virtual const Nucleotide& operator [] (size_t indx) const = 0;
    virtual IDNA* get_slice(size_t beg, size_t end) = 0;
    virtual size_t get_length() const = 0;
    virtual Nucleotide* get_m_seq() = 0;

    virtual IDNA& operator= (const IDNA* other) = 0;
    virtual IDNA& operator= (std::string& other) = 0;
    virtual IDNA& operator= (const char* other) = 0;
    virtual bool operator == (const IDNA* other) = 0;
    virtual bool operator != (const IDNA& other) = 0;

    friend std::ostream& operator<< (std::ostream& os,IDNA* other);
};



#endif //PROJECTDNA_IDNA_H
