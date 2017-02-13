#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("data.in");

    int a, b, c;
    int nr = 0;

    while (fin >> a >> b >> c) {
        if (a + b > c && b + c > a && a + c > b)
            nr ++;
    }

    cout << "The answer for part1 is: " << nr << "\n";

    return 0;
}
