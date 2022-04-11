#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string text;
    getline(cin, text);

    istringstream iss(text);
    string word;
    
    while (iss >> word) 
    {
        // do something here
    }

    return 0;
}