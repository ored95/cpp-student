#include <vector>
#include <iostream>
#include <assert.h>
#include <algorithm>    // swap (to fix error: call to 'swap' is ambiguous
using namespace std;    // if we want to redefine that built-in function)

/**
 * @brief display a vector/array
 * @tparam T element type
 * @param v vector
 */
template <typename T>
void disp(const vector<T> &v)
{
    for (T x: v)
        cout << x << " ";
    cout << endl;
}

/**
 * @brief compare if x is not lower than y
 * @tparam T datatype
 * @param x - fisrt element
 * @param y - second element
 * @return true/false 
 */
template <typename T>
bool cmp(const T& x, const T& y)
{
    return x > y;
}

/**
 * @brief find the second minimum of array
 * @tparam T element type
 * @param a array
 * @return T - the second minimum 
 */
template <typename T>
T secondMin(const vector<T> &a)
{
    assert(a.size() >= 2);
    T m1 = a[0], m2 = a[1];
    if (cmp<T>(m1, m2))
        swap(m1, m2);
        
    for (int i = 2; i < a.size(); i++)
    {
        if (cmp<T>(m1, a[i]))
        {
            m2 = m1;
            m1 = a[i];
        } else if (cmp<T>(m2, a[i]))
            m2 = a[i];
    }
    
    return m2;
}

/**
 * @brief argsort by idea of insertion sort
 * @tparam T element type
 * @param a vector/array
 * @return vector<int> - vector of index by ascending it's value
 */
template <typename T>
vector<int> asort(const vector<T> &a)
{
    vector<int> v;
    for (int i = 0; i < a.size(); i++)
        v.push_back(i);

    for (int j = 1; j < v.size(); j++)
    {
        int key = v[j];
        int i = j-1;
        while (i >= 0 && cmp(a[v[i]], a[key]))
        {
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = key;
    }
    return v;
}

/**
 * @brief partite an array into 2 parts in comparison to pivot value
 * @tparam T element type
 * @param idx list of indexes
 * @param a map-array to get value by list idx 
 * @param lhs left border position
 * @param rhs right border position
 * @return int - pivot position
 */
template <typename T>
int partition(vector<int> &idx, const vector<T> &a, int lhs, int rhs)
{
    int p = idx[rhs];
    int i = lhs - 1;
    for (int j = lhs; j < rhs; j++)
    {
        if (cmp(a[p], a[idx[j]]))
        {
            if (i++ != j)
                swap(idx[j], idx[i]);
        }
    }
    if (i + 1 != rhs)
        swap(idx[i+1], idx[rhs]);
    return i + 1;
}

/**
 * @brief quicksort algorithm
 * @tparam T element type
 * @param idx list of indexes
 * @param a map-array to get value by list idx
 * @param lhs left border position
 * @param rhs right border position
 */
template <typename T>
void quicksort(vector<int> &idx, const vector<T> &a, int lhs, int rhs)
{
    if (lhs < rhs)
    {
        int ip = partition(idx, a, lhs, rhs);
        quicksort(idx, a, lhs, ip-1);
        quicksort(idx, a, ip+1, rhs);
    }
}

/**
 * @brief argsort by idea of quick sort
 * @tparam T element type
 * @param a vector/array
 * @return vector<int> - vector of index by ascending it's value
 */
template <typename T>
vector<int> bsort(const vector<T> &a)
{
    vector<int> v;
    for (int i = 0; i < a.size(); i++)
        v.push_back(i);
    
    quicksort(v, a, 0, a.size() - 1);
    return v;
}
