#include <vector>
#include <iostream>
#include <algorithm>    // swap (to fix error: call to 'swap' is ambiguous
using namespace std;    // if we want to redefine that built-in function)

template <typename T>
void disp(const vector<T> &v)
{
    for (T x: v)
        cout << x << " ";
    cout << endl;
}

template <typename T>
int secondMin(const vector<T> &a)
{
    T m1, m2;
    m1 = m2 = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] < m1)
        {
            m2 = m1;
            m1 = a[i];
        } else if (a[i] < m2)
            m2 = a[i];
        }
    return m2;
}

template <typename T>
bool cmp(const T& x, const T& y)
{
    return x >= y;
}

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

template <typename T>
vector<int> bsort(const vector<T> &a)
{
    vector<int> v;
    for (int i = 0; i < a.size(); i++)
        v.push_back(i);
    
    quicksort(v, a, 0, a.size() - 1);
    return v;
}
