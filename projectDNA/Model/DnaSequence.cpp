//
// Created by kierszen on 12/27/18.
//

#include <cstring>
#include "DnaSequence.h"

DNA::DNA(const char* seq)
{
    size_t size_seq = strlen(seq);
    Nucleotide *arr;

    try
    {
        arr = new Nucleotide[size_seq];
    }

    catch (const char *e) {
        throw e;
    }

    for (int i = 0; i < size_seq; i++)
    {
        arr[i] = seq[i];
    }

    m_seq = arr;
    m_length = size_seq;
}

DNA::DNA(const std::string& seq)
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

    for (int i = 0; i < size_seq; i++)
    {
        arr[i] = seq[i];
    }

    m_seq = arr;
    m_length = size_seq;
}

DNA::DNA(DNA& other)
{
   size_t size_seq = other.m_length;
   m_length = other.m_length;
   Nucleotide *arr;

   try
   {
       arr = new Nucleotide[size_seq];
   }

   catch (const char *e)
   {
       throw e;
   }

   for (int i = 0; i < size_seq; i++)
   {
       arr[i] = other[i];
   }

   m_seq = arr;
   m_length = size_seq;
}

//Nucleotide* DNA:: get_m_seq()
//{
//
//}

Nucleotide& DNA::operator [] (size_t indx)
{
    return m_seq[indx];
}

const Nucleotide& DNA:: operator [] (size_t indx) const
{
    return m_seq[indx];
}

DNA::DNA(const DNA& other,size_t beg, size_t end)
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

IDNA* DNA::get_slice(size_t beg, size_t end)
{
//    DNA dna(*this, beg, end);
//    return ;
}

size_t DNA::get_length() const
{
    return m_length;
}

IDNA& DNA::operator= (const IDNA* other)
        {
            size_t size_seq = other->get_length();
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
            for (int i = 0; i < m_length; i++)
            {
//                arr[i] = other;
            }
            m_seq = arr;
        }
IDNA& DNA::operator= (std::string& other)
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
            for (int i = 0; i < size_seq; i++) {
                m_seq[i] = other[i];
            }

            return *this;
        }

IDNA& DNA::operator= (const char* other)
        {
            int size_seq = strlen(other);
            delete[] m_seq;

            m_length = size_seq;
            m_seq = new Nucleotide[size_seq];

            try {
                for (int i = 0; i < size_seq; i++) {
                    m_seq[i] = other[i];
                }
            }
            catch (const char* e)
            {
                delete [] m_seq;
                throw e;
            }
            return *this;
        }

bool DNA::operator == (const IDNA* other)
{
    for (unsigned int i = 0; i < other.m_length; ++i) {
        if (!(m_seq[i] == other.m_seq[i]))
            return false;
    }
    return true;
}

bool DNA::operator != (const IDNA& other)
{
    if (!(m_seq == other.m_seq))
        return true;
    return false;
}

DNA::~DNA()
{
    std::cout << "DnaSequence Dtor" << endl;
    delete[] m_seq;
}

//friend std::ostream& operator<< (std::ostream& os,IDNA* other);