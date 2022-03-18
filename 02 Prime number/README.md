# Project 02

||Function|Description|
| :---: | :--- | :--- |
|1|**genPrimeTable**|generate prime table up to limit (1000100)|
|2|**isPrimeT1**|check if a prime number by using prime table (type #1)|
|3|**isPrimeT2**|check if a prime number by using modified Euclide algorithm (type #2)|
+ Generating prime table:
```py
# Processor: AMD Ryzen 5 3600 6-Core (12 CPUs), ~3.6GHz
# GPU: NDVIA GeForce GTX 1660 SUPER
# Total generation time: 36.336 ms
```
+ How to build and run test:
```sh
g++ -std=c++11 test.cpp lib.cpp -o test && ./test
```
+ Compare execution time:

|Id|Test case|Type #1 (μs)|Type #2 (μs)|
| :---: | :---: | :---: | :---: |
|1|2|224|0|
|2|97|166|0|
|3|709|51|0|
|4|6491|49|1|
|5|10101|59|0|
|6|1299827|58|3|
|7|472882049|79|64|
|8|4222234741|113|190|
|9|136363636361|531|1118|
|10|1000123465987|769|3838|
> Test passed!