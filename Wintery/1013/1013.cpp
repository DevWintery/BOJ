#include <iostream>
#include <string>
#include <regex>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


void solve()
{
    string str;
    cin >> str;

    regex r("(100+1+|01)+");
    cout << (regex_match(str, r) ? "YES" : "NO") << '\n';
}

int main()
{
    Initialize

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}