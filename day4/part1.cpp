#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int n;
    char c;
} litera;

litera v[26];

bool cmp(litera a, litera b)
{
    if (a.n == b.n)
        return a.c < b.c;

    return a.n > b.n;
}

int parser(char sir[10000])
{

    int id = 0;

    for (int i = 0; i < 26; ++ i) {
        v[i].n = 0;
        v[i].c = i + 'a';
    }

    for (int i = 0; sir[i]; ++ i) {
        while (sir[i] >= 'a' && sir[i] <= 'z') {
            ++ v[sir[i] - 'a'].n;
            ++ i;
        }

        while (sir[i] >= '0' && sir[i] <= '9') {
            id = id * 10 + sir[i] - '0';
            ++ i;
        }

        if (sir[i] == '[') {
            int cnt = 0;

            ++ i;

            sort(v, v + 26, cmp);

            while (sir[i] != ']') {
                if (sir[i] != v[cnt ++].c)
                    return -1;

                ++ i;
            }
        }
    }

    return id;
}

int main()
{
    freopen("data.in", "r", stdin);

    char sir[10000];
    int sum = 0;

    while (gets(sir)) {
        int id = parser(sir);

        if (id == -1)
            continue;
        else
            sum += id;
    }

    printf("%d\n", sum);

    return 0;
}
