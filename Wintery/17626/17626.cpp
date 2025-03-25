#include <iostream>
#include <cmath>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

int dp[50'001];

int main()
{
    Initialize

    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i = 4; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + 1;

        for(int j = 1; j * j <= i; ++ j)
        {
            dp[i] = ::min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n];

    return 0;
}