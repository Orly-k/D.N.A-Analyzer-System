//
// Created by kierszen on 12/25/18.
//

#include <iostream>
#include <cstring>
#include <assert.h>
#include "Nucleotide.h"


Nucleotide::Nucleotide():m_singleNuc('X'){}

Nucleotide::Nucleotide(char c)
{
    if (!isValid((char)toupper(c)))
        throw ("invalid characters");
    m_singleNuc = (char)toupper((c));
}

Nucleotide& Nucleotide::operator= (char c)
        {
            if (!isValid((char)toupper(c)))
                 throw ("invalid characters");
            m_singleNuc = (char)toupper(c);
            return *this;
        }

Nucleotide& Nucleotide::operator= (const Nucleotide& nuc)
        {
            if (!isValid((char)toupper(nuc.m_singleNuc)))
                throw ("invalid characters");
            m_singleNuc = (char)toupper(nuc.m_singleNuc);
            return *this;
        }

Nucleotide Nucleotide::getPair() const
{
    char c = 'X'; //default
    switch (m_singleNuc)
    {
        case 'A':
            c = 'T';
            break;
        case 'T':
            c = 'A';
            break;
        case 'C':
            c = 'G';
            break;
        case 'G':
            c = 'C';
            break;
        default:
            //assert (""); //use assert!, how?
            break;
    }
    return Nucleotide(c);
}

std::ostream & operator << (std::ostream& os, const Nucleotide &Nuc)
{
    os << Nuc.m_singleNuc;
    return os;
}

bool Nucleotide::operator == (const Nucleotide &other)
{
    return(m_singleNuc == other.m_singleNuc);
}

bool Nucleotide::operator != (const Nucleotide &other)
{
    return(m_singleNuc != other.m_singleNuc);
}