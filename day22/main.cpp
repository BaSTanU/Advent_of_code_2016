#include <bits/stdc++.h>

#define Nmax 2000
#define MK make_pair
#define st first
#define nd second

using namespace std;

const int x_axis[4] = {0, 1, 0, -1};
const int y_axis[4] = {1, 0, -1, 0};

int disk_free[Nmax];
int disk_used[Nmax];

int mat_used[50][50];
int mat_size[50][50];

int lee[50][50];

queue < pair < int, int > > Q;

int move_empty_node(int y, int x)
{
    lee[y][x] = 1;
    Q.push(MK(y, x));

    // Now, let's find the number of steps needed to move the empty cell
    // at [(31,0) in xOy] or (0,31) in matrix representation
    while (!Q.empty()) {
        int x = Q.front().nd;
        int y = Q.front().st;

        Q.pop();

        for (int k = 0; k < 4; ++ k) {
            int new_x = x + x_axis[k];
            int new_y = y + y_axis[k];

            if (new_x >= 0 && new_y >= 0 && new_x < 33 && new_y < 31 && !lee[new_y][new_x] && mat_used[new_y][new_x] <= mat_size[y][x]) {
                lee[new_y][new_x] = lee[y][x] + 1;
                Q.push(MK(new_y, new_x));
            }
        }
    }

    return lee[0][31];
}

int find_empty_node()
{
    // Find the empty node <==> mat_used is zero
    for (int i = 0; i < 31; ++ i)
        for (int j = 0; j < 33; ++ j)
            if (!mat_used[i][j])
                return move_empty_node(i, j);
}

int part2()
{
    int steps;

    steps = find_empty_node() + 31 * 5;

    return steps;
}

int part1(int dim)
{
    int sum = 0;

    for (int i = 0; i < dim; ++ i)
        for (int j = 0; j < dim; ++ j) {
            if (i != j && disk_used[i] <= disk_free[j] && disk_used[i])
                ++ sum;
        }

    return sum;
}

int main()
{
    freopen("data.in", "r", stdin);

    string str;
    int a;

    getline(cin, str);
    getline(cin, str);

    for (a = 0; getline(cin, str); ++ a) {
        int num[10];
        int cnt = 0;

        fill(num, num + 10, 0);

        for (int i = 0; i < str.size(); ++ i) {
            if (str[i] >= '0' && str[i] <= '9') {
                while (str[i] >= '0' && str[i] <= '9') {
                    num[cnt] = num[cnt] * 10 + str[i] - '0';
                    ++ i;
                }
                ++ cnt;
            }
        }

        disk_used[a] = num[3];
        disk_free[a] = num[4];

        mat_used[num[1]][num[0]] = num[3];
        mat_size[num[1]][num[0]] = num[2];
    }

    cout << "The answer for part1 is: " << part1(a) << "\n";

    cout << "The answer for part2 is: " << part2() << "\n";

    return 0;
}
