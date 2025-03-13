#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> p;
    vector<int> idx(n, 0);

    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;

        p.push_back({x, y});

        if(i >= n / 2)
            idx[i] = 1;
    }

    double res = 987654321;
    do
    {
        int x = 0;
        int y = 0;

        for(int i = 0; i < n; ++i)
        {
            if(idx[i])
            {
                x += p[i].first;
                y += p[i].second;
            }
            else
            {
                x -= p[i].first;
                y -= p[i].second;
            }
        }

        res = min(sqrt(pow(x, 2) + pow(y, 2)), res);

    } while (next_permutation(idx.begin(), idx.end()));
    
    cout << fixed;
    cout.precision(7);
    cout << res << '\n';
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