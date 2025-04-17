#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    set<char> fist_char;
    for(int i = 0; i < 3; i++)
    {
        string s;
        cin >> s;
        fist_char.emplace(s[0]);
    }

    if(fist_char.count('l') && fist_char.count('k')&& fist_char.count('p'))
    {
        cout << "GLOBAL";
    }
    else
    {
        cout << "PONIX";
    }

    return 0;
}