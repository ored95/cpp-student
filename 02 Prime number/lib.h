#include <cstdint>  // int64_t
#include <vector>
using namespace std;
#define PRLOG "prime.log"

/**
 * @brief generate prime table up to limit number
 * @param limit: int64_t higher border to generate
 * @result prime.log
 */
void genPrimeTable(int64_t);

/**
 * @brief check if a prime number by using prime table
 * @param number: int64_t value to check
 *        list of prime numbers: vector<int64_t>
 * @return true/false 
 */
bool isPrimeT1(int64_t, vector<int64_t>);

/**
 * @brief check if a prime number by using modified Euclide algorithm
 * @param number: int64_t value to check
 * @return true/false 
 */
bool isPrimeT2(int64_t);
