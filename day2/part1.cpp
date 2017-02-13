#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("data.in");

    string str;

    int x = 0, y = 0;

    cout << "The answer for part1 is: ";

    while (fin >> str) {
        for (int i = 0 ; i < str.size(); ++ i) {
            if (str[i] == 'U')
                y = max(-1, y - 1);

            if (str[i] == 'R')
                x = min(1, x + 1);

            if (str[i] == 'D')
                y = min(1, y + 1);

            if (str[i] == 'L')
                x = max(-1, x - 1);
        }

        cout << 5 + y * 3 + x;
    }

    cout << "\n";

    return 0;
}