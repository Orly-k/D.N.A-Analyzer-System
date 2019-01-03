//
// Created by kierszen on 12/27/18.
//

#ifndef PROJECTDNA_DNA_H
#define PROJECTDNA_DNA_H

#include "IDna.h"


class DnaSequence : public IDna
{
public:
    explicit DnaSequence(const char* seq);
    explicit DnaSequence(const std::string& seq);
//    DnaSequence(){}
//    DnaSequence(DnaSequence &other);

    ~DnaSequence();

    Nucleotide& operator [] (size_t indx);
    const Nucleotide& operator [] (size_t indx) const;
    size_t get_length() const;


    Nucleotide* get_m_seq();

//    DnaSequence& operator= (const DnaSequence& other);
    DnaSequence& operator= (std::string& other);
    DnaSequence& operator= (const char* other);

    //    SharedPtr<IDna> get_slice(size_t beg, size_t end);
    //    bool operator == (const DnaSequence &other);//?
//    bool operator != (const DnaSequence &other);//?

    friend std::ostream& operator<< (std::ostream& os,DnaSequence &other);

private:
    Nucleotide* m_seq;
    size_t m_length;
    DnaSequence(const DnaSequence &other,size_t beg,size_t end);

};


#endif //PROJECTDNA_DNA_H
