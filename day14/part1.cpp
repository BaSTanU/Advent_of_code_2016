#include <bits/stdc++.h>

#include "md5.h"

#define MK make_pair
#define IT vector < pair < char , int > > :: iterator

using namespace std;

vector < pair < char , int > > V;
int answer[100];

void check_vector(int ind)
{
	while (ind - V.begin()->second > 1000)
		V.erase(V.begin());
}

void go_number(char numar[], int i)
{
	int cnt = 0;
	char s[1000];
	s[0] = '0';
	numar[0] = '0';
	numar[1] = '\0';

	while (i) {
		s[cnt ++] = (i % 10) + '0';
		i /= 10;
	}

	-- cnt;

	for (int j = cnt; j >= 0; -- j)
		numar[cnt - j] = s[j];

	numar[cnt + 1] = '\0';
}

int main()
{
	char sir[100];
	int nr = 0;

	gets(sir);

	for (int i = 0; nr < 64; ++ i) {
		char s[200], A[200], numar[100];
		int j;

		go_number(numar, i);

		strcpy(s, sir);
		strcat(s, numar);

		string str = md5(s);

		for (int j = 4; j < str.size(); ++ j)
			// check if it validate a key
			if (str[j] == str[j - 1] && str[j] == str[j - 2] && str[j] == str[j - 3] && str[j] == str[j - 4]) {
				check_vector(i);

				bool sw = 1;

				while (sw) {
					IT it;

					sw = 0;
					for (it = V.begin(); it != V.end(); ++ it)
						if (it->first == str[j]) {
							answer[nr ++] = it->second;
							cout << "Found something! " << nr << "\n";
							sw = 1;
							break;
						}

					if (sw)
						V.erase(it);

					if (nr == 64) {
						sort(answer, answer + nr);

						cout << "The answer is: " << answer[62] << " or " << answer[63] << " or " << answer[64] << "\n";

						return 0;
					}
				}
			}

		for (int j = 2; j < str.size(); ++ j)
			// check if it can be a key
			if (str[j] == str[j - 1] && str[j] == str[j - 2]) {
				V.push_back(MK(str[j], i));
				break;
			}
	}

	sort(answer, answer + nr);

	cout << "The answer is: " << answer[63] << "\n";

    return 0;
}

