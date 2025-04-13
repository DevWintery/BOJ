#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Log
{
    int t;
    int a;
    int b;
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    unordered_set<int> viruses(K);
    for(int i = 0; i < K; i ++)
    {
        int x;
        cin >> x;
        viruses.insert(x);
    }

    vector<Log> logs;
    for(int i = 0; i < M; i ++)
    {
        int t, a, b;
        cin >> t >> a >> b;

        logs.push_back({t, a, b});
    }

    ::sort(logs.begin(), logs.end(), [](const Log& a, const Log& b)
    {
        return a.t < b.t;
    });

    for(int i = 1; i <= N; i ++)
    {
        unordered_set<int> current;
        current.insert(i);

        for(const auto& log : logs)
        {
            if(current.count(log.a))
            {
                current.insert(log.b);
            }
        }

        if(current == viruses)
        {
            cout << i;
            break;
        }
    }

    return 0;
}