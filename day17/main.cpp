#include <bits/stdc++.h>

#include "md5.h"

#define P pair < string, pair < int, int > >
#define MK make_pair
#define st first
#define nd second
#define dim 9

using namespace std;

const int x[4] = {0, 0, -1, 1}; // UP, DOWN, LEFT, RIGHT
const int y[4] = {-1, 1, 0, 0}; // in this order
const char L[4] = {'U', 'D', 'L', 'R'};

struct cmp
{
    bool operator()(P const & i, P const & j)
    {
        if (i.st.size() == j.st.size())
        	return i.st < j.st;

       	return i.st.size() > j.st.size();
    }
};

char room[9][9] = { '#', '#', '#', '#', '#', '#', '#', '#', '#', // #########
			 	    '#', ' ', '|', ' ', '|', ' ', '|', ' ', '#', // #S| | | #
				    '#', '-', '#', '-', '#', '-', '#', '-', '#', // #-#-#-#-#
				    '#', ' ', '|', ' ', '|', ' ', '|', ' ', '#', // # | | | #
				    '#', '-', '#', '-', '#', '-', '#', '-', '#', // #-#-#-#-#
				    '#', ' ', '|', ' ', '|', ' ', '|', ' ', '#', // # | | | #
				    '#', '-', '#', '-', '#', '-', '#', '-', '#', // #-#-#-#-#
				    '#', ' ', '|', ' ', '|', ' ', '|', 'V', '#', // # | | | 
				    '#', '#', '#', '#', '#', '#', '#', '#', '#', // ####### V
				};

priority_queue < P, vector < P >, cmp > Q;

int sol;

bool valid_move(char c)
{
	if (c >= 'b' && c <= 'f')
		return 1;
	return 0;
}

int main()
{
    freopen("data.in", "r", stdin);

	string input;
	int nr = 0;

	cin >> input;

	cout << "Program just started! Enjoy ^.^\n\n";

	Q.push(MK(input, MK(1, 1)));

	while (!Q.empty()) {
		string cur_str = Q.top().st;
		int cur_y = Q.top().nd.st;
		int cur_x = Q.top().nd.nd;
		
		Q.pop();
		
		string md5_str = md5(cur_str);

		for (int k = 0; k < 4; ++ k) {
			int new_x = cur_x + x[k];
			int new_y = cur_y + y[k];

			if (room[new_y][new_x] != '#' && valid_move(md5_str[k])) {
				string temp = cur_str;
				temp += L[k];

				new_x += x[k];
				new_y += y[k];

				if (room[new_y][new_x] == 'V') {
					if (!sol) {
						cout << "Part 1 result string is: ";
						for (int i = input.size(); i < temp.size(); ++ i)
							cout << temp[i];
						cout << "\n";
					}

					int damned_size = temp.size() - input.size();

					sol = max(sol, damned_size);
					
				}
				
				else
					Q.push(MK(temp, MK(new_y, new_x)));
			}
		}
	}

	cout << "Part 2 result is: " << sol << "\n\n";

    return 0;
}
