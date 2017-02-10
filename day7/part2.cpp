#include <bits/stdc++.h>

using namespace std;

char br[100][500], nbr[100][500];
int br_cnt, nbr_cnt;
int br_size[100], nbr_size[100];

int SSL_support(char sir[500])
{
    for (int i = 0; i < nbr_cnt; ++ i)
        for (int j = 0; j < nbr_size[i] - 2; ++ j)
            if (nbr[i][j] == nbr[i][j + 2] && nbr[i][j] != nbr[i][j + 1])
                for (int k = 0; k < br_cnt; ++ k)
                    for (int l = 0; l < br_size[k] - 2; ++ l)
                        if (br[k][l] == nbr[i][j + 1] && br[k][l + 2] == nbr[i][j + 1] && br[k][l + 1] == nbr[i][j])
                            return 1;

    return 0;
}

void tokenizer(char sir[500])
{
    int cnt = 0;

    br_cnt = nbr_cnt = 0;

    for (int i = 0; sir[i]; ++ i) {
        if (sir[i] == '[') {
            nbr[nbr_cnt][cnt] = '\0';
            nbr_size[nbr_cnt ++] = cnt;
            cnt = 0;

            for (++ i; sir[i] != ']'; ++ i)
                br[br_cnt][cnt ++] = sir[i];

            br[br_cnt][cnt] = '\0';
            br_size[br_cnt ++] = cnt;
            ++ i;
        }

        nbr[nbr_cnt][cnt ++] = sir[i];
    }

    nbr[nbr_cnt][cnt] = '\0';
    nbr_size[nbr_cnt ++] = cnt;
}

int main()
{
    freopen("data.in", "r", stdin);

    char sir[500];
    int counter = 0;

    while (gets(sir)) {
        tokenizer(sir);

        counter += SSL_support(sir);
    }

    printf("%d", counter);

    return 0;
}