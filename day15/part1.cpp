#include <bits/stdc++.h>

using namespace std;

int nrpos[20];
int pos[20];
int N;

bool check()
{
    for (int i = 0; i < N; ++ i)
        if (((pos[i] + i + 1) % nrpos[i]))
            return 0;

    return 1;
}

int main()
{
    freopen("data1.in", "r", stdin);

    int disc;
    int time;
    char str[100];

    for (N = 0; gets(str); ++ N)
        sscanf(str, "Disc #%d has %d positions; at time=0, it is at position %d", &disc, &nrpos[N], &pos[N]);

    for (time = 0; !check(); ++ time) {
        for (int i = 0; i < N; ++ i)
            pos[i] = (pos[i] + 1) % nrpos[i];
    }

    printf("Result: %d\n", time);

    return 0;
}
