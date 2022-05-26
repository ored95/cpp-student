#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct date {
    int d, m, y;
};

// Source: https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Sakamoto's_methods
// By default: Sun - 0, Mon - 1, Tue - 2, Wed - 3, Thu - 4, Fri - 5, Sat - 6 (mod 7)
const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
int date_to_int(date d) {
    d.y -= d.m < 3;
    return ( d.y + d.y / 4 - d.y / 100 + d.y / 400 + t[d.m - 1] + d.d) % 7;
}

int magic(date d) {
    if (d.m < 3) {
        d.y--; 
        d.m += 12;
    }
    return 365 * d.y + d.y/4 - d.y/100 + d.y/400 + (153 * d.m - 457)/5 + d.d - 306;
}

int main() {
    ifstream fin("plan.txt");
    if (fin.is_open()) {
        int d, m, y;
        fin >> d >> m >> y;
        date begin = { d, m, y };

        fin >> d >> m >> y;
        date end = { d, m, y };

        vector<int> dayoffs;
        while (!fin.eof()) {
            fin >> d;
            dayoffs.push_back(d);
        }

        auto start = high_resolution_clock::now();
        // *** main start here!! ***
        // S1. find total days
        int ndays = magic(end) - magic(begin) + 1;

        // S2. now count total day-offs
        int b = date_to_int(begin);
        int be = b + ndays - 1;
        int n = 0;
        for (int d: dayoffs) {
            // 2.1 unoptimized version O(mn)
            // for (int k = 0; k < ndays; k++) {
            //     cout << b + k << " " << (int)((b+k)%7 == d) << endl;
            //     n += ((b + k - d) % 7 == 0);
            // }

            // 2.2 (a little) optimized version O(mk) where max(k) = 6
            int tb = b;
            while (tb <= be && (tb - d) % 7 != 0)
                tb++;   // first correct day
            if (tb <= be)
                n += 1 + (be - tb) / 7;

            // 2.3 Waiting for O(m) version, i.e. just one formula of dayoffs between two dates
            // Write something here ...
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        
        // S3. Number of working days
        cout << ndays - n << " (" << duration.count() << " microseconds)" << endl;
    } else {
        cout << "Error: file plan not found." << endl;
    }
    fin.close();

    return 0;
}