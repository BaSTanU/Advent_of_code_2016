#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

typedef struct
{
    int type;
    int val;
    char c_val;
    char to;
} INSTRUCTION;

INSTRUCTION ins[100];

int return_value(int ind)
{
    if (ins[ind].c_val) {
        if (ins[ind].c_val == 'a')
            return a;
        if (ins[ind].c_val == 'b')
            return b;
        if (ins[ind].c_val == 'c')
            return c;

        if (ins[ind].c_val == 'd')
            return d;

        return ins[ind].c_val - '0';
    }

    return ins[ind].val;
}

int do_ins(int ind)
{

    if (ins[ind].type == 3) { // incrementation / decrementation
        if (ins[ind].to == 'a')
            a += ins[ind].val;
        if (ins[ind].to == 'b')
            b += ins[ind].val;
        if (ins[ind].to == 'c')
            c += ins[ind].val;
        if (ins[ind].to == 'd')
            d += ins[ind].val;

        return ind + 1;
    }

    if (ins[ind].type == 1) { // copy
        if (ins[ind].to == 'a')
            a = return_value(ind);
        if (ins[ind].to == 'b')
            b = return_value(ind);
        if (ins[ind].to == 'c')
            c = return_value(ind);
        if (ins[ind].to == 'd')
            d = return_value(ind);

        return ind + 1;
    }

    if (ins[ind].type == 2 && return_value(ind)) // jump
        return ind + ins[ind].val;

    return ind + 1;
}

void parser(char str[50], int ind)
{
    if (str[0] == 'i') {
        ins[ind].type = 3;
        ins[ind].to = str[4];
        ins[ind].val = 1;
        return;
    }

    if (str[0] == 'd') {
        ins[ind].type = 3;
        ins[ind].to = str[4];
        ins[ind].val = -1;
        return;
    }

    if (str[0] == 'c') {
        int i = 4, aux = 0;

        ins[ind].type = 1;

        if (str[i] == '-') {
            for (++ i; str[i] >= '0' && str[i] <= '9'; ++ i)
                aux = aux * 10 + str[i] - '0';
            ins[ind].val = - aux;
        }
        else
            if (str[i] >= '0' && str[i] <= '9') {
                for ( ; str[i] >= '0' && str[i] <= '9'; ++ i)
                    aux = aux * 10 + str[i] - '0';
                ins[ind].val = aux;
            }
            else
                ins[ind].c_val = str[i ++];

        ins[ind].to = str[++ i];
        return;
    }

    if (str[0] == 'j') {
        int i = 4, aux = 0;

        ins[ind].type = 2;
        ins[ind].c_val = str[i];
        i += 2;

        if (str[i] == '-') {
            for (++ i; str[i] >= '0' && str[i] <= '9'; ++ i)
                aux = aux * 10 + str[i] - '0';
            ins[ind].val = - aux;
        }
        else {
            for ( ; str[i] >= '0' && str[i] <= '9'; ++ i)
                aux = aux * 10 + str[i] - '0';
            ins[ind].val = aux;
        }

        return;
    }

    if (ins[ind].type == 1) {
        printf("Copy instruction: %c = ", ins[ind].to);
        if (ins[ind].c_val)
            printf("%c\n", ins[ind].c_val);
        else
            printf("%d\n", ins[ind].val);
    }

    if (ins[ind].type == 2)
        printf("Jump to instruction: if(%c) then jump to instruction %d\n", ins[ind].c_val, ins[ind].val);

    if(ins[ind].type == 3)
        printf("Incrementation for %c with %d\n", ins[ind].to, ins[ind].val);
}

int main()
{
    freopen("data.in", "r", stdin);

    char str[50];
    int dim;

    for (dim = 0; gets(str); ++ dim)
        parser(str, dim);

    c = 1;

    for (int i = 0; i < dim; )
        i = do_ins(i);

    printf("%d %d %d %d\n", a, b, c, d);

    return 0;
}
