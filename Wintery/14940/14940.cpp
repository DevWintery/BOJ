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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));

    int x = 0;
    int y = 0;

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            cin >> board[i][j];

            if(board[i][j] == 2)
            {
                y = i;
                x = j;

                board[i][j] = 0;
            }
            else if(board[i][j] == 1)
                board[i][j] = -1;
        }
    }

    const pair<int, int> dir[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    queue<pair<int, int>> q;
    q.push({y, x});

    while(!q.empty())
    {
        auto [y, x] = q.front(); q.pop();

        for(int i = 0; i < 4; i ++)
        {
            int ny = y + dir[i].first;
            int nx = x + dir[i].second;

            if(nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if(board[ny][nx] == -1 && board[ny][nx] != 0)
                {
                    q.push({ny, nx});
                    board[ny][nx] = board[y][x] + 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}