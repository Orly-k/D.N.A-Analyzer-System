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
        SharedPtr(SharedPtr const & other);
        ~SharedPtr();

        SharedPtr<T>& operator = (SharedPtr< T > const& other);
        bool operator!=(const SharedPtr&) const;
        bool operator==(const SharedPtr&) const;

        T* operator->() const;
        T& operator*()  const;
        operator bool() const;


        T* get() const;


    private:

        T*   m_ptr;
        size_t * counter;
    };
#endif //EXCELLENTEAM_ELLA_C_DNA_ORLY_K_SHAREDPTR_H
