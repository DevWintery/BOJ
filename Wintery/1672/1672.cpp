#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<pair<char, char>, char> board =
    {
        {{'A', 'A'}, 'A'},
        {{'A', 'G'}, 'C'},
        {{'A', 'C'}, 'A'},
        {{'A', 'T'}, 'G'},

        {{'G', 'A'}, 'C'},
        {{'G', 'G'}, 'G'},
        {{'G', 'C'}, 'T'},
        {{'G', 'T'}, 'A'},

        {{'C', 'A'}, 'A'},
        {{'C', 'G'}, 'T'},
        {{'C', 'C'}, 'C'},
        {{'C', 'T'}, 'G'},

        {{'T', 'A'}, 'G'},
        {{'T', 'G'}, 'A'},
        {{'T', 'C'}, 'G'},
        {{'T', 'T'}, 'T'},
    };

    int N;
    cin >> N;

    string str;
    cin >> str;

    while(str.length() > 1)
    {
        string s = str.substr(str.length() - 2, 2);

        str.erase(str.length() - 2, 2);
        str += board[{s[0], s[1]}];
    }

    cout << str;

    return 0;
}