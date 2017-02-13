#include <bits/stdc++.h>

using namespace std;

char mat[7][7] = {'0', '0', '0', '0', '0', '0', '0',
                  '0', '0', '0', '1', '0', '0', '0',
                  '0', '0', '2', '3', '4', '0', '0',
                  '0', '5', '6', '7', '8', '9', '0',
                  '0', '0', 'A', 'B', 'C', '0', '0',
                  '0', '0', '0', 'D', '0', '0', '0',
                  '0', '0', '0', '0', '0', '0', '0'};

int main()
{
    ifstream fin("data.in");

    string str;

    int x = 3, y = 1;

    cout << "The answer for part2 is: ";

    while (fin >> str) {
        for (int i = 0 ; i < str.size(); ++ i) {
            if (str[i] == 'U' && mat[x - 1][y] != '0')
                -- x;

            if (str[i] == 'R' && mat[x][y + 1] != '0')
                ++ y;

            if (str[i] == 'D' && mat[x + 1][y] != '0')
                ++ x;

            if (str[i] == 'L' && mat[x][y - 1] != '0')
                -- y;
        }
        
        cout << mat[x][y];
    }

    cout << "\n";

    return 0;
}
