//
// Created by kierszen on 12/28/18.
//

#ifndef EXCELLENTEAM_ELLA_C_DNA_ORLY_K_SHAREDPTR_H
#define EXCELLENTEAM_ELLA_C_DNA_ORLY_K_SHAREDPTR_H

#include <cstddef>

template<typename T>
class SharedPtr
{
    public:
        explicit SharedPtr(T* ptr = NULL);
        SharedPtr(SharedPtr const &other);
        ~SharedPtr();

        SharedPtr<T>& operator = (SharedPtr< T > const& other);
        bool operator!=(const SharedPtr&) const;
        bool operator==(const SharedPtr&) const;

        T* operator->() const;
        T& operator*()  const;
        operator bool() const;

        T* get() const;


    private:

        T *m_ptr;
        size_t *counter;
    };


template <typename T>
SharedPtr<T> :: SharedPtr(T* ptr)
{
    m_ptr = ptr;
    counter = new size_t(1);
}

template <typename T>
SharedPtr<T> :: ~SharedPtr()
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
T& SharedPtr<T> ::operator*()  const
{
    return *m_ptr;
}

template <typename T>
T* SharedPtr<T> ::get() const
{
    return m_ptr;
}

template <typename T>
SharedPtr<T> ::operator bool() const ///?
{
    return m_ptr;
}

template <typename T>
SharedPtr<T> ::SharedPtr(SharedPtr const& other)
{
    this->m_ptr = other.m_ptr;
    ++counter;
    this->counter = other.counter;
}

template <typename T>
SharedPtr<T> & SharedPtr<T> :: operator = (SharedPtr< T > const& other)
{
    if(other.m_ptr != NULL)
        delete other.m_ptr;
    this->m_ptr = other.m_ptr;
    ++counter;
    this->counter = other.counter;

}

template <typename T>
bool SharedPtr<T> ::operator!=(const SharedPtr& other) const
{
    return m_ptr != other.m_ptr;
}

template <typename T>
bool SharedPtr<T> ::operator==(const SharedPtr& other) const
{
    return m_ptr == other.m_ptr;
}
#endif //EXCELLENTEAM_ELLA_C_DNA_ORLY_K_SHAREDPTR_H
