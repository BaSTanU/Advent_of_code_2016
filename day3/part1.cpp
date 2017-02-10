#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("data.in", "r", stdin);

    int a, b, c;
    int nr = 0;

    while (cin >> a >> b >> c) {
        if (a + b > c && b + c > a && a + c > b)
            nr ++;
    }

    printf("%d\n", nr);

    return 0;
}
