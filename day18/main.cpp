#include <bits/stdc++.h>

#define Nmax 200

using namespace std;

char room[2][Nmax];

char get_type(int i, int j)
{
    if (room[i][j - 1] == '^' && room[i][j] == '.' && room[i][j + 1] == '.')
        return '^';

    if (room[i][j - 1] == '.' && room[i][j] == '.' && room[i][j + 1] == '^')
        return '^';

    if (room[i][j - 1] == '^' && room[i][j] == '^' && room[i][j + 1] == '.')
        return '^';

    if (room[i][j - 1] == '.' && room[i][j] == '^' && room[i][j + 1] == '^')
        return '^';

    return '.';
}

int main()
{
    freopen("data.in", "r", stdin);

    char str[Nmax];
    int dim, l = 0, safe_tiles = 0;

    gets(str);

    for (dim = 0; str[dim]; ++ dim)
        room[0][dim + 1] = str[dim];

    room[0][0] = room[1][0] = room[0][dim + 1] = room[1][dim + 1] = '.';

    for (int i = 1; i <= 40; ++ i) {
        for (int j = 1; j <= dim; ++ j)
            if (room[l][j] == '.')
                ++ safe_tiles;

        l = 1 - l;

        for (int j = 1; j <= dim; ++ j)
            room[l][j] = get_type(1 - l, j);
    }
    cout << "For part1, there are " << safe_tiles << " safe tiles!\n";

    for (int i = 41; i <= 400000; ++ i) {
        for (int j = 1; j <= dim; ++ j)
            if (room[l][j] == '.')
                ++ safe_tiles;

        l = 1 - l;

        for (int j = 1; j <= dim; ++ j)
            room[l][j] = get_type(1 - l, j);
    }

    cout << "For part2 there are " << safe_tiles << " safe tiles!\n";

    return 0;
}
