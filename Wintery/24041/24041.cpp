#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Food
{
    long long S;
    long long L;
    int O;
};


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, G, K;
    cin >> N >> G >> K;

    vector<Food> foods;

    for(int i = 0; i < N; i ++)
    {
        long long s, l;
        int o;
        cin >> s >> l >> o;

        foods.push_back({s, l, o});
    }

    long long l = 0;
    long long r = 4'000'000'000;

    int answer = 0;
    while(l <= r)
    {
        priority_queue<long long> pq;

        long long mid = (l + r) / 2;
        long long res = 0;

        for(int i = 0; i < N; i ++)
        {
            long long num = foods[i].S * ::max((long long)1, mid - foods[i].L);
            res += num;

            if(foods[i].O == 1)
            {
                pq.push(num);
            }
        }

        int removed = 0;
        while(!pq.empty() && removed < K)
        {
            res -= pq.top(); 
            pq.pop();
            removed ++;
        }

        if(res <= G)
        {
            answer = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << answer;

    return 0;
}