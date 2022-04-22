#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
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
    date& operator=(const date& other) noexcept {
        // Guard no self assignment
        if (this != &other) {
            d = other.d;
            m = other.m;
            y = other.y;
        }
        return *this;
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
    bool operator<(const date& other) {
        return  ( y < other.y ) || 
                ( y == other.y && m < other.m ) || 
                ( y == other.y && m == other.m && d < other.d );
    }
    bool operator>(const date& other) {
        return  ( y > other.y ) || 
                ( y == other.y && m > other.m ) || 
                ( y == other.y && m == other.m && d > other.d );
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

struct book {
    string title;
    string author;
    string category;
    date releaseDate;
    int page;

    book(string _title, string _author, string _category, date _date, int _page): 
        title(_title), author(_author), category(_category), releaseDate(_date), page(_page) {}
    book(const book &other): 
        title(other.title), author(other.author), category(other.category), releaseDate(other.releaseDate), page(other.page) {}

    // priority: 0 - title, 1 - author, 2 - category, 3 - releaseDate, 4 - page
    bool less(const book &other, int priority) {
        bool cmp;
        switch (priority)
        {
        case 0:
            cmp = title.compare(other.title) < 0; 
            break;
        case 1:
            cmp = author.compare(other.author) < 0; 
            break;
        case 2:
            cmp = category.compare(other.category) < 0; 
            break;
        case 3:
            cmp = releaseDate < other.releaseDate; 
            break;
        default:    // priority = 4
            cmp = page < other.page;
            break;
        }
        return cmp;
    }
};

struct books
{
    vector<book> lst;
    books() { }
    int size() {
        return lst.size();
    }
    const book& operator[] (size_t index) const {
		return lst[index-1];
	}
    void _default() {
        lst.erase(lst.begin(), lst.end());
        ifstream fin ( "books.csv" );
        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            string title, author, category, tmp;
            getline(ss, title, ','); 
            getline(ss, author, ',');
            getline(ss, category, ','); 
            getline(ss, tmp, ','); 
            date releaseDate(tmp);
            getline(ss, tmp, ',');
            int page = stoi(tmp);    
            if (releaseDate.valid && page > 0) {
                book b(title, author, category, releaseDate, page);
                lst.push_back(b);
            }
        }
        fin.close();
    }
    void push_book(const book& b) {
        lst.push_back(b);
    }
    void remove(size_t id) {
        auto it = lst.begin();
        advance(it, id-1);
        lst.erase(it);
    }
    // insertsion sort
    void sort() {
        // TODO
    }
    void disp() {
        for (int i = 0; i < 85; i++) cout << "-";
        for (int i = 0; i < lst.size(); i++) {
            cout << endl <<  "| " << setw(2) << i+1 << " | ";
            cout << setw(20) << lst[i].title << " | ";
            cout << setw(20) << lst[i].author << " | ";
            cout << setw(10) << lst[i].category << " | ";
            cout << lst[i].releaseDate.str() << " | ";
            cout << setw(5) << lst[i].page << " | ";
        }
        cout << endl;
        for (int i = 0; i < 85; i++) cout << "-";
        cout << endl;
    }
};

bool process(books &bks) {
    cout << endl << "***** Menu *****" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Update a book" << endl;
    cout << "3. Remove a book" << endl;
    cout << "4. Search book by filter" << endl;
    cout << "5. Sort books by order" << endl;
    cout << "6. Show all books" << endl;
    cout << "7. Restore to default books list" << endl;
    cout << "[0ther]. Exit program" << endl;
    cout << "Choose an option -> ";
    int choice; cin >> choice;
    if (choice == 1) {
        string _title, _author, _category, tmp;
        cout << "Enter a book detail:" << endl;
        cout << "Title: "; cin >> _title;  // getline(cin, _title);
        cout << "Author: "; cin >> _author;  //getline(cin, _author);
        cout << "Category: "; cin >> _category;  //getline(cin, _category);
        cout << "Release date (as XX.XX.XXXX): "; cin >> tmp;  //getline(cin, tmp);
        date _date(tmp);
        if (_date.valid) {
            int page; 
            cout << "Total pages: "; cin >> page;
            if (page > 0) {
                book b(_title, _author, _category, _date, page);
                bks.push_book(b);
                cout << "A new book is added successfully." << endl;
            } else {
                cout << "Error: Invalid number of page. Add a book failed!" << endl;
            }
        } else {
            cout << "Error: Invalid datetime format. Add a book failed!" << endl;
        }
    } else if (choice == 2) {
        cout << "Which book do you want to update [1-" << bks.size() << "]? ";
        int id; cin >> id;
        if (id >= 1 && id <= bks.size()) {
            // just allow update release date only
            string tmp; cout << "Enter release date (as XX.XX.XXXX): "; cin >> tmp;  //getline(cin, tmp);
            date _date(tmp);
            if (_date.valid) {
                bks.lst[id-1].releaseDate = _date;
                cout << "Result: update book details successfully" << endl;
            } else {
                cout << "Error: Invalid datetime format. Update a book failed!" << endl;
            }
        } else {
            cout << "Error: Invalid book ID";
        }
    } else if (choice == 3) {
        cout << "Which book do you want to remove [1-" << bks.size() << "]? ";
        int id; cin >> id;
        if (id >= 1 && id <= bks.size()) {
            bks.remove(id);
        } else {
            cout << "Error: Invalid book ID";
        }
    } else if (choice == 4) { // allow filter by category, datetime interval
        cout << "select filter (1 - category, 2 - datetime): ";
        int filter; cin >> filter;
        if (filter != 2 && filter != 1) {
            cout << "Error: Unknown filter. Searching failed!" << endl;
        } else {
            if (filter == 2) {
                string start_filter, end_filter;
                cout << "Enter release date start interval (as XX.XX.XXXX): "; cin >> start_filter;  // getline(cin, start_filter);
                cout << "Enter release date end interval (as XX.XX.XXXX): "; cin >> end_filter;  // getline(cin, end_filter);
                date start(start_filter), end(end_filter);
                if (start.valid && end.valid) {
                    for (int id = 1; id <= bks.size(); ) {
                        if (end < bks[id].releaseDate || start > bks[id].releaseDate)
                            bks.remove(id);
                        else
                            id++;
                    }
                } else {
                    cout << "Error: Invalid datetime format. Searching failed!" << endl;
                }
            } else {    // 1
                string category_filter; cout << "Enter a category: "; cin >> category_filter;  // getline(cin, category_filter);
                for (int id = 1; id <= bks.size(); ) {
                    if (bks[id].category.compare(category_filter) != 0)
                        bks.remove(id);
                    else
                        id++;
                    bks.disp();
                }
            }
            if (bks.size() == 0) {
                cout << "Result: No books found." << endl;
                bks._default();     // restore to default  
            } else {
                cout << "Result: " << bks.size() << " book(s) found." << endl;
                bks.disp();
            }
        }
    } else if (choice == 5) {
        // sort
    } else if (choice == 6) {
        bks.disp();
    } else if (choice == 7) {
        bks._default();
        cout << "Result: Books list is restored to default" << endl;
    }
    return 1 <= choice && choice <= 7;
}

int main() {
    books tmp;
    tmp._default();
    tmp.disp();
    while (process(tmp));

    return 0;
}