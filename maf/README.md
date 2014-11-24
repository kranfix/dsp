Moving Average Filter
=====================

This is an algorithm with O(1) to calculate the moving average filter in C++.

## Usage

Supouse you want a 16 order MAF with float type, so you have to code:

```C++
#include <maf.h>

maf<float,16> m();

m.insert(13.4);
float mean = m.mean();
```
