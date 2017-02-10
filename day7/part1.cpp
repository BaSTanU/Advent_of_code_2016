#include <bits/stdc++.h>

using namespace std;

bool decoder(char sir[1000], int length)
{
    bool sw = 0;

    for (int i = 0; i < length - 3; ++ i) {
        if (sir[i] == '[') {
            for (i = i + 1; i < length - 3 && sir[i] != ']'; ++ i)
                if (sir[i] == sir[i + 3] && sir[i + 1] == sir[i + 2] && sir[i] != sir[i + 1])
                    return 0;

            ++ i;
        }

        if (sir[i] == sir[i + 3] && sir[i + 1] == sir[i + 2] && sir[i] != sir[i + 1])
            sw = 1;
    }

    return sw;
}

int main()
{
    char sir[1000];
    int cnt = 0;

    freopen("data.in", "r", stdin);

    while (gets(sir)) {
        int length = 0;

        for (int i = 0; sir[i]; ++ i)
            ++ length;

        if (decoder(sir, length))
            ++ cnt;
    }

    printf("%d", cnt);

    return 0;
}
