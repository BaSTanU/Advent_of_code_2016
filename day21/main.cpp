#include <bits/stdc++.h>

using namespace std;

int unscrab(int ind, int dim, char c, string pass)
{
    string temp;
    string lol;
    string aux = pass + pass;

    for (int i = 0; i < dim; ++ i) {
        int j;

        temp = aux.substr(i, dim);

        for (j = 0; j < dim; ++ j)
            if (temp[j] == c)
                break;

        int steps = j + 1;

        if (j > 3)
            ++ steps;

        steps %= dim;

        lol = temp + temp;
        temp = lol.substr(dim - steps, dim);

        if (pass == temp)
            return i;
    }
}

int main()
{
    freopen("data.in", "r", stdin);

    int dim = 8;

    vector < string > V;
    string ins;
    string pass ("abcdefgh");
    string temp;

    while (getline(cin, ins))
        V.push_back(ins);

    for (int i = 0; i < V.size(); ++ i) {
        ins = V[i];

        if (ins[0] == 's') { // swap cases
            if (ins[5] == 'p') {
                int pos1 = ins[14] - '0';
                int pos2 = ins[30] - '0';
                swap(pass[pos1], pass[pos2]);
                continue;
            }

            if (ins[5] == 'l') {
                char c1 = ins[12];
                char c2 = ins[26];
                for (int i = 0; i < dim; ++ i) {
                    if (pass[i] == c1)
                        pass[i] = c2;
                    else
                        if (pass[i] == c2)
                            pass[i] = c1;
                }
                continue;
            }
        }

        if (ins[0] == 'r') {
            if (ins[7] == 'l') { // rotate left
                int steps = (ins[12] - '0') % dim;
                temp = pass + pass;
                pass = temp.substr(steps, dim);
                continue;
            }

            if (ins[7] == 'r') { // rotate right
                int steps = (ins[13] - '0') % dim;
                temp = pass + pass;
                pass = temp.substr(dim - steps, dim);
                continue;
            }

            if (ins[7] == 'b') {
                char c = ins[35];
                int ind;
                for (ind = 0; ind < dim; ++ ind)
                    if (pass[ind] == c)
                        break;
                int steps = ind + 1;
                if (ind > 3)
                    ++ steps;
                steps %= dim;
                temp = pass + pass;
                pass = temp.substr(dim - steps, dim);
                continue;
            }

            if (ins[8] == 'p') { // reverse
                int pos1 = ins[18] - '0';
                int pos2 = ins[28] - '0';
                for ( ; pos1 < pos2; ++ pos1, -- pos2)
                    swap(pass[pos1], pass[pos2]);
                continue;
            }
        }

        if (ins[0] == 'm') {
            int pos1 = ins[14] - '0';
            int pos2 = ins[28] - '0';
            char c = pass[pos1];
            pass.erase(pos1, 1);
            pass.insert(pos2, 1, c);
            continue;
        }
    }

    cout << "The answer for part1 is: " << pass << "\n";

    pass = "fbgdceah";

    for (int i = V.size() - 1; i >= 0; -- i) {
        ins = V[i];

        if (ins[0] == 's') { // swap cases
            if (ins[5] == 'p') {
                int pos1 = ins[14] - '0';
                int pos2 = ins[30] - '0';
                swap(pass[pos1], pass[pos2]);
                continue;
            }

            if (ins[5] == 'l') {
                char c1 = ins[12];
                char c2 = ins[26];
                for (int i = 0; i < dim; ++ i) {
                    if (pass[i] == c1)
                        pass[i] = c2;
                    else
                        if (pass[i] == c2)
                            pass[i] = c1;
                }
                continue;
            }
        }

        if (ins[0] == 'r') {
            if (ins[7] == 'l') {
                int steps = (ins[12] - '0') % dim;
                temp = pass + pass;
                pass = temp.substr(dim - steps, dim);
                continue;
            }

            if (ins[7] == 'r') {
                int steps = (ins[13] - '0') % dim;
                temp = pass + pass;
                pass = temp.substr(steps, dim);
                continue;
            }

            if (ins[7] == 'b') {
                char c = ins[35];
                int ind;
                for (ind = 0; ind < dim; ++ ind)
                    if (pass[ind] == c)
                        break;
                int steps = unscrab(ind, dim, c, pass);
                temp = pass + pass;
                pass = temp.substr(steps, dim);
                continue;
            }

            if (ins[8] == 'p') { // reverse
                int pos1 = ins[18] - '0';
                int pos2 = ins[28] - '0';
                for ( ; pos1 < pos2; ++ pos1, -- pos2)
                    swap(pass[pos1], pass[pos2]);
                continue;
            }
        }

        if (ins[0] == 'm') {
            int pos1 = ins[14] - '0';
            int pos2 = ins[28] - '0';
            char c = pass[pos2];
            pass.erase(pos2, 1);
            pass.insert(pos1, 1, c);
            continue;
        }
    }

    cout << "The answer for part2 is: " << pass << "\n";

    return 0;
}