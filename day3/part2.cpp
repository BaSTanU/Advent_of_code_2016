#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("data.in");

    int a, b, c, d, e, f, g, h, i;
    int nr = 0;

    while (fin >> a >> b >> c >> d >> e >> f >> g >> h >> i) {
        if (a + d > g && d + g > a && a + g > d)
            nr ++;

        if (b + e > h && b + h > e && e + h > b)
            nr ++;

        if (c + f > i && f + i > c && c + i > f)
            nr ++;
    }

    cout << "The answer for part2 is: " << nr << "\n";

    return 0;
}