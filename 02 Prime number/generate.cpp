#include "lib.h"
#include <chrono>       // time counter
#include <iomanip>      // fixed, setprecision
#include <iostream>
using namespace std;

// Build & run: g++ -std=c++11 generate.cpp lib.cpp -O2 -o prime && ./prime > prime.log

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    genPrimeTable((int64_t)1e6+100);
    auto end = std::chrono::high_resolution_clock::now();
    auto tms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    double time = (double)tms.count() / 1000;
    cout << "Generating prime table time: " << fixed << setprecision(3) << time << " (sec)" << endl;
    return 0;
}