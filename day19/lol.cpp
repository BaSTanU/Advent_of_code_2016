#include <bits/stdc++.h>

using namespace std;

int V[2][4000005];

int main()
{
    freopen("data.in", "r", stdin);

    int elves;
    int power = 1;
    int l = 0;

    cin >> elves;

    for (int i = 1; i <= elves; ++ i)
        V[0][i] = i;

    while (elves > power)
        power <<= 1;

    if (power != elves)
        power >>= 1;

    cout << "The answer for part1 is: " << 2 * (elves - power) + 1 << "\n";

    while (elves > 1) {
        int mid = elves / 2;

        for (int i = 2; i <= mid; ++ i)
            V[1 - l][i - 1] = V[l][i];

        for (int i = mid + 2; i <= elves; ++ i)
            V[1 - l][i - 2] = V[l][i];

        -- elves;
	cout << elves << "\n";

        V[1 - l][elves] = V[l][1];

        l = 1 - l;
    }

    cout << "The answer for part2 is: " << V[1 - l][1] << "\n";

    return 0;
}
