#include "maf.h"

// Constructor
maf::maf() : n(len), p(0), sum(0)
{
    // reserve the mem force 0.0 initial value
    V = new T[n];
    for (int i = 0; i < n; i++) {
        V[i] = 0.0;
    }
}

// Returns the mean of the lastest "n" values
T maf::mean() {
    return sum / n;
}

// Inserts the new value and calculate
// the sum of the lastest "n" values
void maf::insert(T newvalue) {
    V[p] = newvalue;
    sum += newvalue - V[(p+n-1) % n];
    p = (p+1) % n;
}
