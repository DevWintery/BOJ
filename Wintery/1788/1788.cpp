#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);



#define mod 1'000'000'000

int dp[1000001] = {0, 1};

int main()
{
    Initialize

    int n;
    cin >> n;

    int index;

    // N이 음수라면 양수로 바꿔준다.
    if(n < 0)
        index = n * -1;
    else
        index = n;
    
    if(n == 0)
    {
        cout << 0 << '\n' << 0;
        return 0;
    }

    for(int i = 2; i <= index; ++i)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    dp[index] = dp[index] % mod;

    if(n < 0 && index % 2 == 0)
    {
        cout << -1 << '\n' << dp[index];
    }
    else
        cout << 1 << '\n' << dp[index];

    return 0;
}