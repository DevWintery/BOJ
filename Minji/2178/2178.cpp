#include <iostream>
#include <queue>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

int N, M;
int Maze[100][100];
bool Visited[100][100];

// 상, 하, 좌, 우 이동용
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void BFS(int X, int Y)
{
    queue<pair<int, int>> Q;
    Q.push({X,Y});

    Visited[X][Y] = true;

    while(!Q.empty())
    {
        int CurrentX = Q.front().first;
        int CurrentY = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = CurrentX + dx[i];
            int ny = CurrentY + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            {
                continue;
            }

            if(Maze[nx][ny] == 1 && false == Visited[nx][ny])
            {
                Visited[nx][ny] = true;
                Maze[nx][ny] = Maze[CurrentX][CurrentY] + 1; // 거리 갱신
                Q.push({nx, ny});
            }
        }
    }
}

int main()
{
    Initialize

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
    {
        // 붙어서 입력으로 주어지기 때문
        string line;
        cin >> line;

        for (int j = 0; j < M; j++) 
        {
            Maze[i][j] = line[j] - '0'; 
        }
    }

    BFS(0, 0);

    cout << Maze[N - 1][M - 1] << endl;  // 최소 칸 수 출력
    return 0;
    
}