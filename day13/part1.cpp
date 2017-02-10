#include <bits/stdc++.h>

#define MK make_pair

using namespace std;

const int x_axis[4] = {0, 1, 0, -1};
const int y_axis[4] = {1, 0, -1, 0};
const int X = 31;
const int Y = 39;

int mat[1000][1000];
queue < pair <int, int> > Q;

int fill_matrix(int var)
{
    int counter = 0;

    while (var) {
        counter += var & 1;
        var >>= 1;
    }

    if (counter & 1)
        return -1;
    else
        return 0;
}

int main()
{
    freopen("data.in", "r", stdin);

    int N;

    scanf("%d", &N);

    for (int i = 0; i < 1000; ++ i)
        for (int j = 0; j < 1000; ++ j)
            mat[i][j] = fill_matrix(j * j + 3 * j + 2 * i * j + i + i * i + N);

    Q.push(MK(1, 1));

    while (Q.size()) {
        int x = Q.front().first;
        int y = Q.front().second;

        Q.pop();

        for (int k = 0; k < 4; ++ k) {
            int new_x = x_axis[k] + x;
            int new_y = y_axis[k] + y;

            if (new_y >= 0 && new_x >= 0 && !mat[new_y][new_x]) {
                mat[new_y][new_x] = mat[y][x] + 1;
                Q.push(MK(new_x, new_y));
            }

            if (new_y == Y && new_x == X) {
                printf("Result: %d", mat[Y][X]);
                return 0;
            }
        }
    }

    return 0;
}