#include <bits/stdc++.h>

using namespace std;

char sir[100000];
char cod[100];
char mat[7][7] = {'0', '0', '0', '0', '0', '0', '0',
                  '0', '0', '0', '1', '0', '0', '0',
                  '0', '0', '2', '3', '4', '0', '0',
                  '0', '5', '6', '7', '8', '9', '0',
                  '0', '0', 'A', 'B', 'C', '0', '0',
                  '0', '0', '0', 'D', '0', '0', '0',
                  '0', '0', '0', '0', '0', '0', '0'};
int n;

int main()
{
    freopen("data.in", "r", stdin);

    int x = 3, y = 1;

    while (gets(sir)) {
        for (int i = 0 ; sir[i]; ++ i) {
            if (sir[i] == 'U' && mat[x - 1][y] != '0')
                -- x;

            if (sir[i] == 'R' && mat[x][y + 1] != '0')
                ++ y;

            if (sir[i] == 'D' && mat[x + 1][y] != '0')
                ++ x;

            if (sir[i] == 'L' && mat[x][y - 1] != '0')
                -- y;
        }
        cod[n ++] = mat[x][y];
    }

    cod[n] = '\0';
    puts(cod);

    return 0;
}
