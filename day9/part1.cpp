#include <bits/stdc++.h>

using namespace std;

char str[1000000];
char decompressed[1000000];

int main()
{
    freopen("data.in", "r", stdin);

    gets(str);

    for (int i = 0; str[i]; ++ i) {
        if (str[i] == '(') {
            int nr1 = 0, nr2 = 0;

            for (++ i; str[i] != 'x'; ++ i)
                nr1 = nr1 * 10 + str[i] - '0';

            for (++ i; str[i] != ')'; ++ i)
                nr2 = nr2 * 10 + str[i] - '0';

            ++ i;

            for ( ; nr2; -- nr2)
                strncat(decompressed, str + i, nr1);

            i += nr1 - 1;
        }
        else {
            int length = strlen(decompressed);

            decompressed[length] = str[i];
            decompressed[length + 1] = '\0';
        }
    }

    printf("Length of the decompressed string: %d", strlen(decompressed));

    return 0;
}
