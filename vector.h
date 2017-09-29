#include <vector>
#include <iostream>
#ifndef S3_VECTOR_VECTOR_H
#define S3_VECTOR_VECTOR_H

template <typename T>
class TVector {
private:
    T* Vec;
    size_t Size;
    size_t Count;

public:
    TVector()= default;

    TVector(const TVector& a){
        Size = a.Size;
        Count = a.Count;
        Vec = new T[Size];
       for( size_t i=0; i< Size; ++i){
           Vec[i] = a.Vec[i];
       }
    }

    TVector(TVector&& a){
        Vec = a.Vec;
        Size = a.Size;
        Count = a.Count;
        a.Vec = 0;
    }

    TVector& operator=(const TVector& a){
        if (this == &a)
            return *this;

        if(Vec != nullptr)
            delete[] Vec;

        Size = a.Size;
        Count = a.Count;
        Vec = new T[Size];
        for(size_t i = 0; i < Size; ++i)
            Vec[i] = a.Vec[i];
    }

    TVector& operator=(TVector&& a){
        if (this == &a)
            return *this;

        if(Vec != nullptr)
            delete[] Vec;

        Size = a.Size;
        Count = a.Count;
        Vec = a.Vec;
    }

    ~TVector()
    {
        if(Vec != nullptr)
            delete[] Vec;
    }
};

#endif //S3_VECTOR_VECTOR_H
