#include <bits/stdc++.h>

using namespace std;

char sir[100000];
char cod[100];
int n;

int main()
{
    freopen("data.in", "r", stdin);

    int dx = 0, dy = 0;

    while (gets(sir)) {
        for (int i = 0 ; sir[i]; ++ i) {
            if (sir[i] == 'U')
                dx = max(-1, dx - 1);

            if (sir[i] == 'R')
                dy = min(1, dy + 1);

            if (sir[i] == 'D')
                dx = min(1, dx + 1);

            if (sir[i] == 'L')
                dy = max(-1, dy - 1);
        }
        cod[n ++] = (5 + dx * 3 + dy) + '0';
    }

    cod[n] = '\0';
    puts(cod);

    return 0;
}