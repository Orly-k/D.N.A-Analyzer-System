//
// Created by kierszen on 12/27/18.
//

#ifndef PROJECTDNA_IDNA_H
#define PROJECTDNA_IDNA_H

#include "Nucleotide.h"
#include "SharedPtr.h"

class IDna
{
public:
    virtual Nucleotide& operator [] (size_t indx) = 0;
    virtual const Nucleotide& operator [] (size_t indx) const = 0;

    virtual size_t get_length() const = 0;

    virtual Nucleotide* get_m_seq() = 0;

    //    virtual SharedPtr<IDna> get_slice(size_t beg, size_t end) = 0;
//    virtual bool operator == (const IDna &other) = 0;
//    virtual bool operator != (const IDna &other) = 0;

    virtual ~IDna(){} //std::cout<<"IDna dtor"<<std::endl;}

//    friend std::ostream& operator<< (std::ostream& os, SharedPtr<IDna> other);
};

//std::ostringstream& operator<<(std::ostringstream& oss, const SharedPtr<IDna>& dna)
//{
//    for (unsigned int i = 0; i < 40; ++i)
//    {
//        oss << dna->get_m_seq()[i];
//    }
//    return oss;
//}


#endif //PROJECTDNA_IDNA_H
