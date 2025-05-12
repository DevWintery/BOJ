#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define MOD 1'000'000'007

long long concatenate(long long a, long long b) 
{
    long long temp = b;
    long long digits = 10;

    while (temp >= 10) 
    {
        temp /= 10;
        digits = (digits * 10) % MOD;
    }
    
    return (a * digits % MOD + b) % MOD;
}


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> houses(N + 1);
    vector<vector<int>> graphs(N + 1, vector<int>());

    for (int i = 0; i < N; i++)
    {
        cin >> houses[i + 1];
    }

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        graphs[a].push_back(b);
        graphs[b].push_back(a);
    }

    for (int i = 0; i < Q; i++)
    {
        int start, end;
        cin >> start >> end;

        vector<bool> visit(N + 1, false);

        queue<pair<int, long long>> q;
        q.push({start, houses[start]});
        visit[start] = true;

        while (true)
        {
            auto [cur, answer] = q.front();
            q.pop();

            if (cur == end)
            {
                cout << answer << '\n';
                break;
            }

            for (int graph : graphs[cur])
            {
                if (visit[graph] == false)
                {
                    long long t = concatenate(answer, houses[graph]);
                    q.push({graph, t});
                    visit[graph] = true;
                }
            }
        }
    }

    return 0;
}