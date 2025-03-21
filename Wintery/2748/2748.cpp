#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


long long dp[91];
int target;

void solve(int n)
{
    if(n > target)
        return;

    dp[n] = dp[n - 1] + dp[n - 2];

    solve(n + 1);
}

int main()
{
    Initialize

    cin >> target;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    solve(3);

    cout << dp[target];

    return 0;
}