#include <iostream>
#include <string>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

void solve()
{
    string str;
    cin >> str;

    cout << str[0] << str[str.size() - 1] << '\n';
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