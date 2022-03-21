#include "lib.hpp"

int main()
{
    bool ans = true;
    
    // secondMin
    ans &= (secondMin<int>({3, 1, 5, 2, 1}) == 1);
    ans &= (secondMin<int>({0, 1, 5, 2, 1}) == 1);
    ans &= (secondMin<string>({"a1", "a12", "a21", "a2345", "a2"}) == "a12");
    
    // T: int
    ans &= (secondMin<int>({3, 1, 5, 2, 6, 4}) == 2);
    vector<int> va = asort<int>({3, 1, 5, 2, 6, 4});
    ans &= (va[2] == 0);
    ans &= (va[3] == 5);

    va = bsort<int>({3, 1, 5, 2, 6, 4});
    ans &= (va[1] == 3);
    ans &= (va[0] == 1);

    // T: char
    string s = "justatestforthisproject";
    vector<char> lst(s.begin(), s.end());
    disp<char>(lst);
    va = asort(lst);
    vector<char> result = {
        'a','c','e','e','f','h','i','j','j','o','o','p','r','r','s','s','s','t','t','t','t','t','u'
    };

    auto vb = bsort(lst);
    for (int i = 0; i < lst.size(); i++)
        ans &= (lst[va[i]] == lst[vb[i]]) && (lst[va[i]] == result[i]);

    if (ans)
        cout << "Test passed!" << endl;
    else
        cout << "Test failed!" << endl;
    return 0;
}