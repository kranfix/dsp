#include "maf.h"

// Constructor
template<class T, int len> maf<T,len>::maf() : n(len), p(0), sum(0)
{
    // reserve the mem force 0.0 initial value
    V = new T[len];
    for (int i = 0; i < n; i++) {
        V[i] = 0.0;
    }
}

// Returns the mean of the lastest "n" values
template<class T,int len> T maf<T,len>::mean() {
    return sum / n;
}

// Inserts the new value and calculate
// the sum of the lastest "n" values
template<class T,int len> void maf<T,len>::insert(T newvalue) {
    V[p] = newvalue;
    sum += newvalue - V[(p+n-1) % n];
    p = (p+1) % n;
}
