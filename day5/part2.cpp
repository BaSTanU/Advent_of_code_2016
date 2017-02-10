#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "md5.h"

using std::cout; using std::endl;

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

int main(int argc, char *argv[])
{
	char sir[100], cod[9];
	int nr = 0;

	for (int i = 0; i < 9; ++ i)
		cod[i] = '\0';

	gets(sir);

	for (int i = 0; nr < 8; ++ i) {
		char s[200], A[200], numar[100];
		int j;

		go_number(numar, i);

		strcpy(s, sir);
		strcat(s, numar);

		std::string str = md5(s);

		for (j = 0; j < 5; ++ j)
			if (str.at(j) != '0') 
				break;
			
		if (j == 5 && (str.at(5) >= '0' && str.at(5) <= '7') && cod[str.at(5) - '0'] == '\0') {
			cod[str.at(5) - '0'] = str.at(6);
			++ nr;
			cout << i << " si cifra: " << str.at(6) << '\n';
		}
	}

	puts(cod);

    return 0;
}

