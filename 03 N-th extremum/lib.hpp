#include <vector>
#include <iostream>
using namespace std;

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
    return x > y;
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
