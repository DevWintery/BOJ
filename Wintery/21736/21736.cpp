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

    const pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int N, M;
    cin >> N >> M;

    pair<int, int> start;
    vector<vector<char>> campus(N, vector<char>(M));
    vector<vector<bool>> visit(N, vector<bool>(M, false));
    for(size_t i = 0; i < N; i ++)
    {
        for(size_t j = 0; j < M; j ++)
        {
            cin >> campus[i][j];

            if(campus[i][j] == 'I')
            {
                start = {i, j};
                visit[i][j] = true;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);

    int answer = 0;

    while(!q.empty())
    {
        auto [y, x] = q.front(); q.pop();

        for(int i = 0; i < 4; i ++)
        {
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;

            if(nx >= 0 && nx < M && ny >= 0 && ny < N)
            {
                if(visit[ny][nx] == false && campus[ny][nx] != 'X')
                {
                    if(campus[ny][nx] == 'P')
                    {
                        answer ++;
                    }
                    visit[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }

    if(answer == 0)
        cout << "TT";
    else
        cout << answer
        ;

    return 0;
}