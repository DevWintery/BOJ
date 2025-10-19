#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> visit;

void dfs(const vector<vector<int>>& friends, int index, int depth)
{
    visit[index] = true;

    if(depth >= 2)
    {
        return;
    }
    
    for(const auto& fri : friends[index])
    {
        dfs(friends, fri, depth + 1);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> friends(n + 1);
    visit.resize(n + 1);
    visit[1] = true;

    for(int i = 0; i < m; i ++)
    {
        int a, b;
        cin >> a >> b;

        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    dfs(friends, 1, 0);

    int answer = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(visit[i])
        {
            answer ++;
        }
    }
    cout << answer - 1;

    return 0;
}