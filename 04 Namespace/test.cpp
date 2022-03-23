#include <iostream>
#include "chess.h"
using namespace std;
using namespace chess;

int main()
{
    posion begin;
    cout << "Input beginning posion (column, row): ";
    cin >> begin.column >> begin.row;
    if (in_scope(begin))
        show_moves(begin);
    else
        cout << "Error: Invalid input posion.\n";
    return 0;
}