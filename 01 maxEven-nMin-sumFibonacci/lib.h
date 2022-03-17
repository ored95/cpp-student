#include <vector>
#include <iostream>
using namespace std;

/**
 * @brief search the maximum among the even elements of the sequence
 * @param vector<int> sequence as a list
 * @return int
 * @exception return -1 when the list is empty or there are no even elements
 */
int maxEven(vector<int>);

/**
 * @brief find the number of elements equal to its smallest element
 * @param vector<int> sequence as a list
 * @return int 
 * @exception return 0 when the list is empty
 */
int nMin(vector<int>);

/**
 * @brief check if a Fibonacci number
 * @details Source: https://en.wikipedia.org/wiki/Fibonacci_number#Identification
 * @return true/false 
 */
bool isFibonacci(int);

/**
 * @brief calculate sum of Fibonacci numbers in the sequence
 * @param vector<int> sequence as a list
 * @return int 
 * @exception if there are no such numbers then return 0
 */
int sumFibonacci(vector<int>);