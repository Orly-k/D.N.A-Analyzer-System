//
// Created by kierszen on 12/27/18.
//

#ifndef PROJECTDNA_DNA_H
#define PROJECTDNA_DNA_H

#include "IDNA.h"

class DNA : public IDNA
{
public:
    explicit DNA(const char* seq);
    explicit DNA(const std::string& seq);
    DNA(DNA& other);
//    Nucleotide* get_m_seq();

    Nucleotide& operator [] (size_t indx);
    const Nucleotide& operator [] (size_t indx) const;
    IDNA* get_slice(size_t beg, size_t end);
    size_t get_length() const;

    IDNA& operator= (const IDNA* other);
    IDNA& operator= (std::string& other);
    IDNA& operator= (const char* other);
    bool operator == (const IDNA* other);
    bool operator != (const IDNA& other);

    friend std::ostream& operator<< (std::ostream& os,IDNA* other);

    ~DNA();

private:
    Nucleotide* m_seq;
    size_t m_length;
    DNA(const DNA& other,size_t beg,size_t end);

};


#endif //PROJECTDNA_DNA_H
