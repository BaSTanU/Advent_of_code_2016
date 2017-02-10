#include <bits/stdc++.h>

#define NMAX 1500 
#define START 600

using namespace std;

const int dir_x[4] = {0, 1, 0, -1};
const int dir_y[4] = {1, 0, -1, 0};

int direction[NMAX];
int steps[NMAX];
int mat[NMAX][NMAX];

int getOrientation(int nr)
{
	if (nr == -1)
		return 3;

	if (nr == 4)
		return 0;

	return nr;
}

int getNumber(string str, int &ind)
{
	int nr = 0;

	for (++ ind; isdigit(str[ind]); ++ ind)
		nr = nr * 10 + str[ind] - '0';

	return nr;
}

void parser(int &N)
{
	ifstream fin("data.in");

	string str;

	getline(fin, str);

	for (int i = 0; i < str.size(); ++ i) {
		if (str[i] == 'R') { 
			direction[N] = 1;
			steps[N] = getNumber(str, i);
			++ N;
		}

		if (str[i] == 'L') { 
			direction[N] = -1;
			steps[N] = getNumber(str, i);
			++ N;
		}
	}
}

int main()
{
	int N = 0;
	int dir_act = 0, dx = 0, dy = 0;

	parser(N);

	for (int i = 0; i < N; ++ i) {
		dir_act = getOrientation(dir_act + direction[i]);
		dx = dx + dir_x[dir_act] * steps[i];
		dy = dy + dir_y[dir_act] * steps[i];
	}

	cout << "The answer for part1 is: " << abs(dx) + abs(dy) << "\n";

	dx = dy = START;
	dir_act = 0;
	mat[START][START] = 1;

	for (int i = 0; i < N; ++ i) {
		dir_act = getOrientation(dir_act + direction[i]);
		int new_dx = dx + dir_x[dir_act] * steps[i];
		int new_dy = dy + dir_y[dir_act] * steps[i];

		if (dir_act == 0)
            for (int j = dy + 1; j <= new_dy; ++ j) {
                if (mat[j][dx] == 1) {
                	cout << "The answer for part2 is: " << abs(dx - 600) + abs(j - 600) << "\n";
                    return 0;
                }

                mat[j][dx] = 1;
            }

        if (dir_act == 1)
            for (int j = dx + 1; j <= new_dx; ++ j) {
                if (mat[dy][j] == 1) {
                    cout << "The answer for part2 is: " << abs(dy - 600) + abs(j - 600) << "\n";
                    return 0;
                }

                mat[dy][j] = 1;
            }

        if (dir_act == 2)
            for (int j = dy - 1; j >= new_dy; -- j) {
                if (mat[j][dx] == 1) {
                    cout << "The answer for part2 is: " << abs(dx - 600) + abs(j - 600) << "\n";
                    return 0;
                }

                mat[j][dx] = 1;
            }

        if (dir_act == 3)
            for (int j = dx - 1; j >= new_dx; -- j) {
                if (mat[dy][j] == 1) {
                    cout << "The answer for part2 is: " << abs(dy - 600) + abs(j - 600) << "\n";
                    return 0;
                }

                mat[dy][j] = 1;
            }

        dx = new_dx;
        dy = new_dy;
	}
}