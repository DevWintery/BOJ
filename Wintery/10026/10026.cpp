#include <iostream>
#include <vector>

using namespace std;

inline void Initialize()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

int N;

char board[101][101];

void dfs(int y, int x, vector<vector<bool>>& visit, bool blindness)
{
    visit[y][x] = true;

    for(int i = 0; i < 4; i ++)
    {
        int nx = x + dirX[i];
        int ny = y + dirY[i];
        
        if(nx >= 0 && nx < N && ny >= 0 && ny < N && visit[ny][nx] == false)
        {
            if(blindness)
            {
                //내 색상이 R이나 G면
                bool RG = board[y][x] == 'R' || board[y][x] == 'G';

                //다음 색상도 R이나 G면
                bool nRG = board[ny][nx] == 'R' || board[ny][nx] == 'G';
                
                if(RG && nRG)
                    dfs(ny, nx, visit, blindness);
                else if(board[ny][nx] == board[y][x])
                    dfs(ny, nx, visit, blindness);
            }
            else
            {
                if(board[ny][nx] == board[y][x])
                    dfs(ny, nx, visit, blindness);
            }
        }
    }
}

void solution(bool blindness)
{
    vector<vector<bool>> visit(N, vector<bool>(N, false));

    int answer = 0;
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < N; j ++)
        {
            if(visit[i][j] == false)
            {
                visit[i][j] = true;
                dfs(i, j, visit, blindness);
                answer ++;
            }
        }
    }
    cout << answer << ' ';
}

int main()
{
    Initialize();

    cin >> N;

    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < N; j ++)
        {
            cin >> board[i][j];
        }
    }

    solution(false);
    solution(true);

    return 0;
}