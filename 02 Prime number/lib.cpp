#include "lib.h"
#include <math.h>   // sqrt
#include <list>     // list::remove_if
#include <iostream>

void genPrimeTable(int64_t limit)
{
    list<int64_t> numbers;
    for (int64_t x = 3; x < limit; x += 2)
        numbers.push_back(x);

    cout << "2\t";
    static int64_t p;
    while (numbers.size() > 0)
    {
        p = *(numbers.begin());
        cout << p << "\t";
        numbers.remove_if([](int64_t x) {
            return x % p == 0;
        });
    }
}

bool isPrimeT1(int64_t n, vector<int64_t> primes)
{
    if (n < 2) return false;
    else if (n == 2) return true;
    for (int i = 0; primes[i] <= (int64_t)sqrt(n); i++)
        if (n % primes[i] == 0)
            return false;
    return true;
}

bool isPrimeT2(int64_t n)
{
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0)
        return false;
    else
    {
        for (int64_t b = 3; b <= (int64_t)sqrt(n); b += 2)
            if (n % b == 0)
                return false;
    }
    return true;
}
