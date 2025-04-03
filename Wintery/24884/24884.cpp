#include <iostream>
#include <vector>
#include <functional>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

int N, W, T, K;

int solve(vector<int> firePowers)
{
    int answer = 0;

    function<void(int, int, vector<int>, int)> dfs = [&](int position, int time, vector<int> fires, int addPosition)
    {
        //화력 감소

        vector<int> decreases(N, 0);

        for(int i = 0; i < N; i ++)
        {
            //이전 시간에 장작을 넣은 곳은 화력이 감소하지않는다.
            if(addPosition == i)
            {
                continue;
            } 

            int adjacent = 0;

            if(i > 0 && fires[i-1] > 0)
                adjacent ++;
            if(i < N-1 && fires[i+1] > 0)
                adjacent ++;

            if(adjacent == 0)
                decreases[i] = 3;
            else if(adjacent == 1)
                decreases[i] = 2;
            else if(adjacent == 2)
                decreases[i] = 1;
        }

        //화력 감소 적용
        for(int i = 0; i < N; i ++ )
        {
            fires[i] -= decreases[i];
        }

        // 기저
        if (time == T)
        {
            int activeFires = 0;
            for (const auto &fire : fires)
            {
                if (fire > 0)
                    activeFires++;
            }

            if (activeFires >= K)
                answer++;

            return;
        }

        //시뮬레이션

        // 현재 위치
        dfs(position, time + 1, fires, position);

        //왼쪽 이동
        if(position > 0)
            dfs(position - 1, time + 1, fires, position - 1);

        //오른쪽 이동
        if(position < N-1)
            dfs(position + 1, time + 1, fires, position + 1);
    };

    dfs(W, 1, firePowers, -1);

    return answer;
}

int main()
{
    Initialize
    
    cin >> N >> W >> T >> K;

    vector<int> fires(N, 0);
    for(int i = 0; i < N; i ++)
    {
        cin >> fires[i];
    }

    cout << solve(fires);
    
    return 0;
}