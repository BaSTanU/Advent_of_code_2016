#include <bits/stdc++.h>

#define RIT string :: reverse_iterator

using namespace std;

void do_checksum(string &str)
{
    string temp;

    for (int i = 1; i < str.size(); i += 2) {
        if (str[i] == str[i - 1])
            temp.push_back('1');
        else
            temp.push_back('0');
    }

    str = temp;
}

void make_bigger(string &str)
{
    string temp;
    temp = str;
    reverse(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); ++ i) {
        if (temp[i] == '0')
            temp[i] = '1';
        else
            temp[i] = '0';
    }

    str.push_back('0');
    str += temp;
}

int main()
{
    freopen("data1.in", "r", stdin);

    int disk_length;
    string str;

    cin >> disk_length >> str;

    while (str.size() < disk_length)
        make_bigger(str);

    str.resize(disk_length);

    do {
        do_checksum(str);
    } while(!(str.size() & 1));

    cout << "Your checksum for part1 is: " << str << "\n";

    freopen("data2.in", "r", stdin);

    cin >> disk_length >> str;

    while (str.size() < disk_length)
        make_bigger(str);

    str.resize(disk_length);

    do {
        do_checksum(str);
    } while(!(str.size() & 1));

    cout << "Your checksum for part2 is: " << str << "\n";

    return 0;
}
