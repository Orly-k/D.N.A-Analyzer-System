//
// Created by kierszen on 12/27/18.
//

#ifndef PROJECTDNA_DNA_H
#define PROJECTDNA_DNA_H

#include "IDNA.h"

class DnaSequence : public IDNA
{
public:
    explicit DnaSequence(const char* seq);
    explicit DnaSequence(const std::string& seq);
    DnaSequence(DnaSequence &other);
//    Nucleotide* get_m_seq();

    Nucleotide& operator [] (size_t indx);
    const Nucleotide& operator [] (size_t indx) const;
//    SharedPtr<IDNA> get_slice(size_t beg, size_t end);
    size_t get_length() const;

    SharedPtr<IDNA> operator= (const SharedPtr<IDNA> other);
    SharedPtr<IDNA> operator= (std::string& other);
    SharedPtr<IDNA> operator= (const char* other);
    bool operator == (const DnaSequence &other);
    bool operator != (const DnaSequence &other);

    friend std::ostream& operator<< (std::ostream& os,SharedPtr<IDNA> other);

    ~DnaSequence();

private:
    Nucleotide* m_seq;
    size_t m_length;
    DnaSequence(const DnaSequence &other,size_t beg,size_t end);

};


#endif //PROJECTDNA_DNA_H
