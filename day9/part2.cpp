#include <bits/stdc++.h>

using namespace std;

char str[100000];

long long decompresser(int ind, int how_much)
{
    long long cnt = 0;

    for (int i = ind; i < how_much; ++ i) {
        int nr1 = 0, nr2 = 0;

        if (str[i] == '(') {
            for (++ i; str[i] != 'x'; ++ i)
                nr1 = nr1 * 10 + str[i] - '0';

            for (++ i; str[i] != ')'; ++ i)
                nr2 = nr2 * 10 + str[i] - '0';

            cnt += nr2 * decompresser(++ i, i + nr1 + 1);

            i += nr1 - 1;
        }

        else
            ++ cnt;
    }

    return cnt;
}

int main()
{
    freopen("data.in", "r", stdin);

    gets(str);

    printf("%lld", decompresser(0, strlen(str)));

    return 0;
}
