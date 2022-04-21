#include <iostream>
#include <fstream>
// #include <string>
using namespace std;

struct date {
    int d;  // day
    int m;  // month
    int y;  // year
    bool valid; // valid datetime
    date(const date& date) {
        d = date.d;
        m = date.m;
        y = date.y;
        valid = date.valid;
    }
    date(string s) {
        valid = isValid(s);
    }
    // check valid datetime format xx.xx.xxxx
    bool isValid(string s)
    {
        if (s.length() != 10 && s[2] != '.' && s[5] != '.')
            return false;
        
        d = ( s[0] - '0' ) * 10 + ( s[1] - '0' );
        m = ( s[3] - '0' ) * 10 + ( s[4] - '0' );
        y = ( s[6] - '0');
        for (int i = 7; i <= 9; i++)
            y = y * 10 + ( s[i] - '0' );
        
        if (y >= 1000 && y <= 2022)
        {
            // check leap year
            if ( (m == 2) && (d == 29) && 
               ( ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0) ))
                return true;
            if (( (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (1 <= d && d <= 31) ) || 
                ( (m == 4 || m == 6 || m == 9 || m == 11) && (1 <= d && d <= 30) ) || 
                ( (m == 2) && (1 <= d && d <= 28) ))
                return true;
        }
        return false;
    }
    // date to string
    string str() {
        string fmt = (d < 10)? "0" : "";
        fmt += to_string(d);
        fmt += (m < 10)? ".0" : ".";
        fmt += to_string(m) + "." + to_string(y);
        return fmt;
    }
};

int main() {
    ifstream fin ( "book.in" );
    int n;
    fin >> n;
    while (n--) {
        string s;
        fin >> s;
        date d(s);
        if (d.valid)
            cout << d.str() << endl;
    }
    fin.close();
    return 0;   
}