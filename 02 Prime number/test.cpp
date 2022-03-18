#include "lib.h"
#include <chrono>
#define NOW std::chrono::steady_clock::now()
#define TOTALTIME(begin, end) std::chrono::duration_cast<std::chrono::microseconds>(end - begin)
#include <iostream>
#include <fstream>
using namespace std;

vector<int64_t> primes;

bool test(int64_t x)
{
    auto begin = NOW;
    bool t1 = isPrimeT1(x, primes);
    auto end = NOW;
    auto tms = TOTALTIME(begin, end);
    cout << "Test case x=" << x << "\tT1: " << tms.count() << "\tT2: ";
    begin = NOW;
    bool t2 = isPrimeT2(x);
    end = NOW;
    tms = TOTALTIME(begin, end);
    cout << tms.count() << endl;
    return t1 && t2;
}

int main()
{
    ifstream ifs (PRLOG);
    int64_t x;
    while (!ifs.eof())
    {
        ifs >> x;
        primes.push_back(x);
    }
    ifs.close();

    bool ans = true;
    ans &= !isPrimeT1(1, primes) && !isPrimeT2(1);
    ans &= test(2);
    ans &= test(97);
    ans &= test(709);
    ans &= test(6491);
    ans &= !test(10101);
    ans &= test(1299827);
    ans &= test(472882049);
    ans &= test(4222234741);
    ans &= test(136363636361);
    ans &= test(1000123465987);

    if (ans)
        cout << "Test passed!" << endl;
    else
        cout << "Test failed!" << endl;
    return 0;
}