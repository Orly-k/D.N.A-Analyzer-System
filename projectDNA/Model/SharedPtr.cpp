//
// Created by kierszen on 12/28/18.
//

#include "SharedPtr.h"

template <typename T>
SharedPtr< T> :: SharedPtr(T* ptr)
{
    m_ptr = ptr;
    counter = new size_t(1);
}

template <typename T>
SharedPtr< T> :: ~SharedPtr()
{
    if (*counter > 1)
        --(*counter);
    else {
        delete m_ptr;
        delete counter;
    }

}

template <typename T>
T* SharedPtr< T> ::operator->() const
{
    return m_ptr;
}

template <typename T>
T& SharedPtr< T> ::operator*()  const
{
    return *m_ptr;
}

template <typename T>
T* SharedPtr< T> ::get() const
{
    return m_ptr;
}

template <typename T>
SharedPtr< T> ::operator bool() const
{
    return m_ptr;
}

template <typename T>
SharedPtr< T> ::SharedPtr(SharedPtr const& other)
{
    this->m_ptr = other.m_ptr;
    ++counter;
    this->counter = other.counter;
}

template <typename T>
SharedPtr< T> & SharedPtr<T> :: operator = (SharedPtr< T > const& other)
{
    if(other.m_ptr != NULL)
        delete other.m_ptr;
    this->m_ptr = other.m_ptr;
    ++counter;
    this->counter = other.counter;

}

template <typename T>
bool SharedPtr< T> ::operator!=(const SharedPtr& other) const
{
    return m_ptr != other.m_ptr;
}

template <typename T>
bool SharedPtr< T> ::operator==(const SharedPtr& other) const
{
    return m_ptr == other.m_ptr;
}