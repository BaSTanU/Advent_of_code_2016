#include <bits/stdc++.h>

#define MK make_pair
#define st first
#define nd second

using namespace std;

const int x_axis[4] = {0, 1, 0, -1};
const int y_axis[4] = {1, 0, -1, 0};

char mat[100][1000];
int G[15][15];
int X[15], Y[15];
int N, M, pairs;
int part1_sol = 1 << 30;
int part2_sol = 1 << 30;
bool visited[15];

void find_path(int ind, int temp, int step)
{
    if (step == pairs) {
        part1_sol = min(part1_sol, temp);
        part2_sol = min(part2_sol, temp + G[ind][0]);
        return;
    }

    for (int i = 1; i < pairs; ++ i)
        if (!visited[i]) {
            visited[i] = 1;
            find_path(i, temp + G[ind][i], step + 1);
            visited[i] = 0;
        }
}

void construct_graph()
{
    int lee[100][1000];

    for (int i = 0; i < pairs; ++ i) {
        for (int j = 0; j < N; ++ j)
            fill(lee[j], lee[j] + M, 0);

        queue < pair < int, int > > Q;

        Q.push(MK(Y[i], X[i]));

        lee[Y[i]][X[i]] = 1;

        while (!Q.empty()) {
            int x = Q.front().nd;
            int y = Q.front().st;

            Q.pop();

            for (int k = 0; k < 4; ++ k) {
                int new_y = y + y_axis[k];
                int new_x = x + x_axis[k];

                if (mat[new_y][new_x] != '#' && !lee[new_y][new_x]) {
                    Q.push(MK(new_y, new_x));
                    lee[new_y][new_x] = lee[y][x] + 1;
                }
            }
        }

        for (int j = 0; j < pairs; ++ j)
            if (j != i)
                G[i][j] = G[j][i] = lee[Y[j]][X[j]] - 1;
    }
}

int main()
{
    freopen("data.in", "r", stdin);

    while (gets(mat[N])) {
        for (int i = 0; mat[N][i]; ++ i)
            if (mat[N][i] >= '0' && mat[N][i] <= '9') {
                X[mat[N][i] - '0'] = i;
                Y[mat[N][i] - '0'] = N;
                ++ pairs;
            }
        ++ N;
    }

    M = strlen(mat[0]);

    construct_graph();

    find_path(0, 0, 1);

    cout << "The answer for part1 is: " << part1_sol << "\n";

    cout << "The answer for part2 is: " << part2_sol << "\n";

    return 0;
}
