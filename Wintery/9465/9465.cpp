#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> posts (2, vector<int>(n, 0));
    vector<vector<int>> dp (2, vector<int>(n, 0));

    for(int i = 0; i < 2; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            int x;
            cin >> x;

            posts[i][j] = x;
        }
    }

    dp[0][0] = posts[0][0];
    dp[1][0] = posts[1][0];

    dp[0][1] = posts[0][1] + posts[1][0];
    dp[1][1] = posts[0][0] + posts[1][1];

    for(int i = 2; i < n; i ++)
    {
        dp[0][i] += posts[0][i] + ::max(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] += posts[1][i] + ::max(dp[0][i - 1], dp[0][i - 2]);
    }

    cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}