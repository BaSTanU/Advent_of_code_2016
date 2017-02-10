#include <bits/stdc++.h>

#include "md5.h"

using namespace std;

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

	for (int i = 0; nr < 8; ++ i) {
		char s[200], A[200], numar[100];
		int j;

		go_number(numar, i);

		strcpy(s, sir);
		strcat(s, numar);

		string str = md5(s);

		for (j = 0; j < 5; ++ j)
			if (str.at(j) != '0')
				break;

		if (j == 5) {
			++ nr;
			cout << i << " si cifra: " << str.at(5) << '\n';
		}
	}

    return 0;
}

