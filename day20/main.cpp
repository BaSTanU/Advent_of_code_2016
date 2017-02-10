#include <bits/stdc++.h>

#define Nmax 1000

using namespace std;

typedef struct {
    long long st, nd;
} ADDRESSES;

bool cmp(ADDRESSES i, ADDRESSES j)
{
    if (i.st == j.st)
        return i.nd < j.st;
    return i.st < j.st;
}

ADDRESSES IP[Nmax];
ADDRESSES allowed[Nmax];
long long sum;

int main()
{
    freopen("data.in", "r", stdin);

    int dim, cnt = 0;
    long long x, y;
    char ch;

    for (dim = 0; cin >> IP[dim].st >> ch >> IP[dim].nd; ++ dim);

    sort(IP, IP + dim, cmp);

    for (int i = 0; i < dim; ) {
        x = IP[i].st;
        y = IP[i].nd;

        for (++ i ; i < dim && IP[i].st <= y; ++ i)
            y = max(y, IP[i].nd);

        allowed[cnt].st = x;
        allowed[cnt].nd = y;

        ++ cnt;
    }

    allowed[cnt].st = (long long) 4294967296;

    cout << "The answer for part 1 is: " << allowed[0].nd + 1 << "\n";

    for (int i = 0; i < cnt; ++ i)
        sum += allowed[i + 1].st - allowed[i].nd - 1;

    cout << "The answer for part 2 is: " << sum << "\n";

    return 0;
}
