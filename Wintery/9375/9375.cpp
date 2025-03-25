#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

void solve()
{
    unordered_map<string, int> map;

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        string name;
        string kind;

        cin >> name >> kind;

        map[kind] += 1;
    }

    int ans = 1;
    for(const auto& m : map)
    {
        ans *= m.second + 1;
    }

    cout << ans - 1 << '\n';
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