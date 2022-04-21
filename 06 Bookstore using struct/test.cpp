#include <iostream>
#include <sstream>
using namespace std;

struct date {
    int day;
    int month;
    int year;
    bool valid;
    // date format: xx.xx.xxxx
    date(string s) {
        try {
            int d = ( s[0] - '0' ) * 10 + ( s[1] - '0' );
            int m = ( s[3] - '0' ) * 10 + ( s[4] - '0' );
            int y = ( s[6] - '0');
            for (int i = 7; i <= 9; i++)
                y = y * 10 + ( s[i] - '0' );
            if ( isValid(d, m, y) ) {
                day = d;
                month = m; 
                year = y;
            }
        } catch (exception& ex) {
            cout << "Error on parsing datetime: " << ex.what() << endl;
        }
    }
    // check valid datetime
    bool isValid(int d, int m, int y)
    {
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
    void str() {
        string fmt = "";
        fmt += (day < 10)? "0%d." : "%2d.";
        fmt += (month < 10)? "0%d." : "%2d.";
        fmt += "%4d";
        printf(fmt.c_str(), day, month, year);
    }
};

struct book {
    int id;
    string title;
    
};

int main() {
    string s = "12.12.2995";
    date d(s);
    cout << d.isValid(s).str();
    return 0;   
}