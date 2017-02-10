#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int low;
    int high;
    char clow;
    char chigh;
} COMMAND;

typedef struct
{
    int high;
    int low;
    vector <int> output;
    queue <COMMAND> commands;
} BOT;

BOT bot[215];
queue <int> order;

bool check(int ind)
{
    if (bot[ind].low && bot[ind].high)
        return 1;
    return 0;
}

bool insert_value(int ind, int val)
{
    if (bot[ind].low) {
        order.push(ind);
        if (bot[ind].low > val) {
            bot[ind].high = bot[ind].low;
            bot[ind].low = val;
        } else {
            bot[ind].high = val;
        }
        return 1;
    }

    bot[ind].low = val;
    return 0;
}

void do_commands(int ind)
{
    if (!bot[ind].commands.size()) {
        printf("He have a problem here!\n");
        return;
    }

    char c1 = bot[ind].commands.front().clow; // the low decision - bot/output
    char c2 = bot[ind].commands.front().chigh; // the high decision - bot/output
    int nr1 = bot[ind].commands.front().low; // the bot who gets the low value
    int nr2 = bot[ind].commands.front().high; // the bot who gets the high value
    int low = bot[ind].low;
    int high = bot[ind].high;

    bot[ind].low = bot[ind].high = 0;
    bot[ind].commands.pop();
    order.pop();

    if (c1 == 'b' && insert_value(nr1, low))
        do_commands(nr1);
    if (c1 == 'o')
        bot[nr1].output.push_back(low);

    if (c2 == 'b' && insert_value(nr2, high))
        do_commands(nr2);
    if (c2 == 'o')
        bot[nr2].output.push_back(high);

}

void parser(char str[])
{
    int nr1 = 0, nr2 = 0, nr3 = 0, i;

    if (str[0] == 'v') {
        for (i = 0; !(str[i] >= '0' && str[i] <= '9'); ++ i);

        for ( ; str[i] >= '0' && str[i] <= '9'; ++ i)
            nr1 = nr1 * 10 + str[i] - '0';

        for ( ; !(str[i] >= '0' && str[i] <= '9'); ++ i);

        for ( ; str[i] >= '0' && str[i] <= '9'; ++ i)
            nr2 = nr2 * 10 + str[i] - '0';

        insert_value(nr2, nr1);
    }
    else {
        char c1, c2;
        COMMAND aux;

        for (i = 4; str[i] >= '0' && str[i] <= '9'; ++ i)
            nr1 = nr1 * 10 + str[i] - '0';

        i += 14;
        if (str[i] == 'o') {
            c1 = 'o';
            i += 7;
        } else {
            c1 = 'b';
            i += 4;
        }
        for ( ; str[i] >= '0' && str[i] <= '9'; ++ i)
            nr2 = nr2 * 10 + str[i] - '0';

        i += 13;
        if (str[i] == 'o') {
            c2 = 'o';
            i += 7;
        } else {
            c2 = 'b';
            i += 4;
        }
        for ( ; str[i] >= '0' && str[i] <= '9'; ++ i)
            nr3 = nr3 * 10 + str[i] - '0';

        aux.low = nr2;
        aux.high = nr3;
        aux.clow = c1;
        aux.chigh = c2;
        bot[nr1].commands.push(aux);
    }
}

int main()
{
    freopen("data.in", "r", stdin);

    char str[100];

    while (gets(str))
        parser(str);

    while (order.size())
        do_commands(order.front());

    printf("%d\n", bot[0].output.front() * bot[1].output.front() * bot[2].output.front());

    return 0;
}