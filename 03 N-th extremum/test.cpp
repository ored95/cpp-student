#include "lib.hpp"

int main()
{
    vector<int> a = {3, 1, 5, 2, 6, 4};
    disp(a);
    auto va = asort(a);
    disp(va);
    cout << a[va[1]] << " " << secondMin(a) << endl;
    cout << endl;
    
    vector<char> b = {'v','m','n','a'};
    disp(b);
    swap(b[1], b[2]);
    disp(b);
    auto vb = asort(b);
    cout << b[vb[1]] << " " << (char)secondMin(b) << endl;
    return 0;
}