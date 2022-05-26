# Project 07

## Problem
```Find total working days between two dates```

## Build and run
```sh
g++ -std=c++11 test.cpp -o test && ./test
```
## Input 
```txt
// plan.txt
<day> <month> <year>    // begining date
<day> <month> <year>    // ending date
<d1> [<d2> ...]         // dayoffs list, here dk is from 0 to 6
                        // By default: Sun - 0, Mon - 1, Tue - 2,
                        //             Wed - 3, Thu - 4, Fri - 5, Sat - 6
```
## Example
+ Input
```
5 5 2022
2 6 2022
4 0
```
+ Output
```
20 (0 microseconds)
```