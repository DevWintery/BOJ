#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int INF = 1e9;

int N;
int W[16][16];
int dp[1 << 16][16];

int tsp(int visit, int cur)
{
    //탐색 완료
    if(visit == (1 << N) - 1)
    {
        if(W[cur][0] == 0)
        {
            return INF;
        }
        return W[cur][0];
    }

    int& ret = dp[visit][cur];
    if(ret != -1)
    {
        return ret;
    }

    ret = INF;

    for(int i = 0; i < N; i ++)
    {
        if(W[cur][i] == 0)
        {
            continue; //갈 수 없음
        }
        
        if(visit & (1 << i))
        {
            continue; //이미 방문
        }

        int cost = W[cur][i] + tsp(visit | (1 << i), i);
        ret = ::min(ret, cost);
    }

    return ret;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < N; j ++)
        {
            cin >> W[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << tsp(1, 0);

    return 0;
}