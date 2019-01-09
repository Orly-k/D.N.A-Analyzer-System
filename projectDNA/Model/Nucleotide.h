//
// Created by kierszen on 12/25/18.
//

#ifndef PROJECT_DNA_NUCLEOTIDE_H
#define PROJECT_DNA_NUCLEOTIDE_H

#include <cstring>
#include <iostream>

class Nucleotide
{

public:
    Nucleotide();
    Nucleotide(char c);
    Nucleotide& operator= (char c);
    Nucleotide& operator= (const Nucleotide& nuc);

    char getNucleotide(){ return m_singleNuc;}
    bool isValid(char c);
    Nucleotide getPair() const;

    bool operator == (const Nucleotide &other);
    bool operator != (const Nucleotide &other);

    friend std::ostream &operator << (std::ostream &os, const Nucleotide &c);

private:
    char m_singleNuc;
};


inline bool Nucleotide::isValid(char c)
{
    return (c=='A' || c=='C' || c=='T' || c=='G');
}

#endif //PROJECT_DNA_NUCLEOTIDE_H
