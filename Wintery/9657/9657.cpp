#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int dp[1001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    dp[4] = 1;

    //홀수 짝수만 체크하면됨
    for(int i = 5; i <= N; i ++)
    {
        if(dp[i - 1] % 2 == 0)
        {
            dp[i] = dp[i - 1]  + 1;
        }
        else if(dp[i - 3] % 2 == 0)
        {
            dp[i] = dp[i - 3] + 1;
        }
        else
        {
            dp[i] = dp[i - 4] + 1;
        }
    }

    if(dp[N] % 2 == 0)
    {
        cout << "CY";
    }
    else
    {
        cout << "SK";
    }

    return 0;
}