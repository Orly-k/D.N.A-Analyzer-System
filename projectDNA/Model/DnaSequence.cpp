//
// Created by kierszen on 12/27/18.
//

#include <cstring>
#include "DnaSequence.h"

DnaSequence::DnaSequence(const char* seq)
{
    size_t size_seq = strlen(seq);
    Nucleotide *arr;

    try
    {
        arr = new Nucleotide[size_seq];
    }
    catch (const char *e)
    {
        throw e;
    }

    for (size_t i = 0; i < size_seq; i++)
    {
        arr[i] = seq[i];
    }

    m_seq = arr;
    m_length = size_seq;
}

DnaSequence::DnaSequence(const std::string& seq)
{
    size_t size_seq = seq.length();
    Nucleotide *arr;

    try
    {
        arr = new Nucleotide[size_seq];
    }

    catch (const char *e)
    {
        throw e;
    }

    for (size_t i = 0; i < size_seq; i++)
    {
        arr[i] = seq[i];
    }

    m_seq = arr;
    m_length = size_seq;
}

DnaSequence::DnaSequence(DnaSequence &other)
{
   size_t size_seq = other.m_length;
   m_length = size_seq;
   Nucleotide *arr;

   try
   {
       arr = new Nucleotide[size_seq];
   }

   catch (const char *e)
   {
       throw e;
   }

   for (size_t i = 0; i < size_seq; i++)
   {
       arr[i] = other[i];
   }

   m_seq = arr;
   m_length = size_seq;
}

Nucleotide* DnaSequence:: get_m_seq()
{
    return this->m_seq;
}

Nucleotide& DnaSequence::operator [] (size_t indx)
{
    return m_seq[indx];
}

const Nucleotide& DnaSequence:: operator [] (size_t indx) const
{
    return m_seq[indx];
}

DnaSequence::DnaSequence(const DnaSequence &other,size_t beg, size_t end)
{
    if (end > other.m_length || beg > end) {
        throw std::out_of_range("get_slice");
    }
    size_t size_seq = end - beg;

    m_seq = new Nucleotide[size_seq];

    for (size_t i = 0, j = beg; i < size_seq; ++i, ++j) {
        m_seq[i] = other.m_seq[j];
    }
    m_length = size_seq;
}

DnaSequence::~DnaSequence()
{
    std::cout << "DnaSequence Dtor" << std::endl;
    delete[] m_seq;
}

std::ostream& operator<< (std::ostream& os,DnaSequence &other)
{
    for (size_t i = 0; i < other.m_length ; ++i)
    {
        os<<other.m_seq[i];
    }
    return os;
}
//SharedPtr<IDna> DnaSequence::get_slice(size_t beg, size_t end)
//{
//    return DnaSequence(*this, beg, end);
//}

size_t DnaSequence::get_length() const
{
    return m_length;
}

DnaSequence& DnaSequence::operator= (const IDna& other)
        {
            size_t size_seq = other.get_length();
            delete[] m_seq;

            m_length = size_seq;

            Nucleotide* arr;

            try
            {
                arr = new Nucleotide[size_seq];
            }
            catch (const char *e)
            {
                throw e;
            }
            for (size_t i = 0; i < m_length; i++)
            {
                arr[i] = other[i];
            }
            m_seq = arr;

            return *this;
        }

DnaSequence& DnaSequence::operator= (std::string& other)
        {
            size_t size_seq = other.length();
            delete[] m_seq;

            m_length = size_seq;

            try
            {
                m_seq = new Nucleotide[size_seq];
            }
            catch (const char *e)
            {
                throw e;
            }
            for (size_t i = 0; i < size_seq; i++) {
                m_seq[i] = other[i];
            }

            return *this;
        }

DnaSequence& DnaSequence::operator= (const char* other)
        {
            size_t size_seq = strlen(other);
            delete[] m_seq;

            try
            {
                m_seq = new Nucleotide[size_seq];
            }
            catch (const char* e)
            {
                throw e;
            }

            for (size_t i = 0; i < size_seq; i++) {
                m_seq[i] = other[i];
            }

            m_length = size_seq;

            return *this;
        }

//bool DnaSequence::operator == (const DnaSequence &other)
//{
//    for (size_t i = 0; i < other.m_length; ++i) {
//        if (!(m_seq[i] == other.m_seq[i]))
//            return false;
//    }
//    return true;
//}
//
//bool DnaSequence::operator != (const DnaSequence &other)
//{
//    for (size_t i = 0; i < other.m_length; ++i) {
//        if (m_seq[i] != other.m_seq[i])
//            return true;
//    }
//    return false;
//}

