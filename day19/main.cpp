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

    while (elves > power)
        power <<= 1;

    if (power != elves)
        power >>= 1;

    cout << "The answer for part1 is: " << 2 * (elves - power) + 1 << "\n";

    power = 1;

    while (power < elves)
        power *= 3;

    power /= 3;

    int res = elves - power;

    if (res > power)
        res += res - power ;

    if (elves == 1)
        cout << "The answer for part 2 is: 1\n";
    else
        cout << "The answer for part2 is: " << res << "\n";

    return 0;
}
