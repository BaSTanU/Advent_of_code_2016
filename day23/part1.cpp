#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int a, b, c, d;
int dim;

typedef struct {
    int type;
    /*
    Type is:
       1 - incrementation
       2 - decrementation
       3 - toggle
       4 - copy
       5 - jump
    */
    int *val;
    int *to;
} INSTRUCTION;

INSTRUCTION ins[50];

void parser(string str, int dim);
void get_register(char c, int *&to);
int do_instruction(int ind);

int main()
{
    freopen("data.in", "r", stdin);

    string str;

    a = 7;

    for (dim = 0; getline(cin, str); ++ dim)
        parser(str, dim);

    for (int i = 0; i < dim; )
        i = do_instruction(i);

    cout << "The answer for part1 is: " << a << "\n";

    return 0;
}

int do_instruction(int ind)
{
    if (ins[ind].type == 1) { // incrementation
        ++ (*ins[ind].to);
        return ind + 1;
    }

    if (ins[ind].type == 2) { // decrementation
        -- (*ins[ind].to);
        return ind + 1;
    }

    if (ins[ind].type == 3) { // toggle
        int temp = *ins[ind].to + ind;

        if (temp < 0 || temp >= dim) // check if an attempt is made to toggle an instruction outside the program
            return ind + 1;

        switch (ins[temp].type) {
            case 1:
                ins[temp].type = 2;
                break;
            case 2:
                ins[temp].type = 1;
                break;
            case 3:
                ins[temp].type = 1;
                break;
            case 4:
                ins[temp].type = 5;
                break;
            case 5:
                ins[temp].type = 4;
                break;
        }
        return ind + 1;
    }

    if (ins[ind].type == 4) { // copy
        // check if copy instruction is valid
        if (ins[ind].to != &a && ins[ind].to != &b && ins[ind].to != &c && ins[ind].to != &d)
            return ind + 1;

        *ins[ind].to = *ins[ind].val;

        return ind + 1;
    }

    if (ins[ind].type == 5) { // jump
        if (*ins[ind].val)
            return ind + *ins[ind].to;

        return ind + 1;
    }

}

void get_register(char ch, int *&to)
{

    if (ch == 'a') {
        to = &a;
        return;
    }
    if (ch == 'b') {
        to = &b;
        return;
    }
    if (ch == 'c') {
        to = &c;
        return;
    }
    if (ch == 'd') {
        to = &d;
        return;
    }
}

void parser(string str, int ind)
{
    // incrementation
    if (str[0] == 'i') {
        ins[ind].type = 1;
        get_register(str[4], ins[ind].to);
        return;
    }

    // decrementation
    if (str[0] == 'd') {
        ins[ind].type = 2;
        get_register(str[4], ins[ind].to);
        return;
    }

    // toggle
    if (str[0] == 't') {
        ins[ind].type = 3;
        get_register(str[4], ins[ind].to);
        return;
    }

    // copy
    if (str[0] == 'c') {
        int i = 4;
        int aux = 0;

        if (str[i] == '-') {
            for (++ i; str[i] >= '0' && str[i] <= '9'; ++ i)
                aux = aux * 10 + str[i] - '0';
            ins[ind].val = new int;
            *ins[ind].val = -aux;
        }
        else
            if (str[i] >= '0' && str[i] <= '9') {
                for ( ; str[i] >= '0' && str[i] <= '9'; ++ i)
                    aux = aux * 10 + str[i] - '0';
                ins[ind].val = new int;
                *ins[ind].val = aux;
            }
            else {
                get_register(str[i], ins[ind].val);
                ++ i;
            }
        ins[ind].type = 4;
        get_register(str[i + 1], ins[ind].to);
        return;
    }

    if (str[0] == 'j') {
        int aux = 0;
        int i = 4;
        if (str[i] == '-') {
            for (++ i; str[i] >= '0' && str[i] <= '9'; ++ i)
                aux = aux * 10 + str[i] - '0';

            ins[ind].val = new int;
            *ins[ind].val = -aux;
        }
        else
            if (str[i] >= '0' && str[i] <= '9') {
                for ( ; str[i] >= '0' && str[i] <= '9'; ++ i)
                    aux = aux * 10 + str[i] - '0';

                ins[ind].val = new int;
                *ins[ind].val = aux;
            }
            else {
                get_register(str[i], ins[ind].val);
                ++ i;
            }

        ++ i;

        if (str[i] == '-') {
            for (++ i; str[i] >= '0' && str[i] <= '9'; ++ i)
                aux = aux * 10 + str[i] - '0';

            ins[ind].to = new int;
            *ins[ind].to = - aux;
        }
        else
            if (str[i] >= '0' && str[i] <= '9') {
                for ( ; str[i] >= '0' && str[i] <= '9'; ++ i)
                    aux = aux * 10 + str[i] - '0';

                ins[ind].to = new int;
                *ins[ind].to = aux;
            }
            else
                get_register(str[i], ins[ind].to);

        ins[ind].type = 5;
        return;
    }
}
