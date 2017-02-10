#include <bits/stdc++.h>

using namespace std;

bool mat[10][60];
bool v[60];
int N = 50, M = 6;

void get_numbers(char sir[50], int a, int &nr1, int &nr2)
{
    bool sw = 1;

    for ( ; sw; ++ a)
        while (sir[a] >= '0' && sir[a] <= '9') {
            nr1 = nr1 * 10 + sir[a] - '0';
            ++ a;
            sw = 0;
        }

    sw = 1;

    for ( ; sw; ++ a)
        while (sir[a] >= '0' && sir[a] <= '9') {
            nr2 = nr2 * 10 + sir[a] - '0';
            ++ a;
            sw = 0;
        }
}

void tokenizer(char sir[50])
{
    char s[50];
    int a, nr1 = 0, nr2 = 0;

    for (a = 0; sir[a] != ' '; ++ a)
        s[a] = sir[a];

    s[a ++] = '\0';

    if (!strcmp(s, "rect")) {
        for ( ; sir[a] != 'x'; ++ a)
            nr1 = nr1 * 10 + sir[a] - '0';

        for (++ a; sir[a]; ++ a)
            nr2 = nr2 * 10 + sir[a] - '0';

        for (int i = 0; i < nr2; ++ i)
            for (int j = 0; j < nr1; ++ j)
                mat[i][j] = 1;

        return ;
    }

    if (!strcmp(s, "rotate")) {
        get_numbers(sir, a, nr1, nr2);

        if (sir[a] == 'r') {
            for (int i = 0; i < N; ++ i)
                v[i] = mat[nr1][i];

            for (int i = 0; i < N; ++ i)
                mat[nr1][(i + nr2) % N] = v[i];
        }
        else {
            for (int i = 0 ; i < M; ++ i)
                v[i] = mat[i][nr1];

            for (int i = 0 ;i < M; ++ i)
                mat[(i + nr2) % M][nr1] = v[i];
        }

        return ;
    }
}

int main()
{
    freopen("data.in", "r", stdin);

    char sir[50];
    int s = 0;

    while (gets(sir))
        tokenizer(sir);

    for (int i = 0; i < M; ++ i, printf("\n"))
        for (int j = 0; j < N; ++ j)
            if (mat[i][j])
                printf("#");
            else
                printf(".");

    return 0;
}
