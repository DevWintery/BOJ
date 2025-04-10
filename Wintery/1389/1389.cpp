#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);

    for(int i = 0; i < M; i ++)
    {
        int x, y;
        cin >> x >> y;
        
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int answer = 98654312;
    int person = -1;
    for(int i = 1; i <= N; i ++)
    {
        queue<int> q;
        vector<int> distance(N + 1, - 1);
        
        q.push(i);
        distance[i] = 0;

        while(!q.empty())
        {
            int current = q.front(); q.pop();

            for(int next : graph[current])
            {
                if(distance[next] == -1)
                {
                    distance[next] = distance[current] + 1;
                    q.push(next);
                }
            }
        }
        
        int sum = 0;
        for(int j = 0; j <= N; j ++)
        {
            if(j != i)
            {
                sum += distance[j];
            }
        }

        if(sum < answer)
        {
            answer = sum;
            person = i;
        }
    }

    cout << person;

    return 0;
}