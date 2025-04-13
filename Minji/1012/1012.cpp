#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

map<pair<int,int>, bool> Farm;
map<pair<int,int>, bool> Visited;

int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1}; 

void DFS(pair<int, int> Point)
{
    stack<pair<int,int>>s;
    s.push(Point);
    Visited[Point] = true;

    // 스택이 비었다는 것은 Point 에서 도달 가능한 모든 배추를 탐색했음을 의미
    while(!s.empty())
    {
        pair<int, int> Current = s.top();
        s.pop();

        // 한 지점으로부터 인접한 배추들을 탐색
        for(int i = 0; i < 4; i++)
        {
            pair<int,int> AroundPoint = {Current.first + dx[i], Current.second + dy[i]};

            // 주변에 배추가 심어져 있고 방문하지 않았을 때 스택에 추가
            if(Farm[AroundPoint] && false == Visited[AroundPoint])
            {
                Visited[AroundPoint] = true;
                s.push(AroundPoint);
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 0;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        int M,N, TotalPlantCount = 0;
        cin >> M >> N >> TotalPlantCount;

        Farm.clear();
        Visited.clear();

        for(int i = 0; i < TotalPlantCount; i++)
        {
            pair<int, int> Point;
            cin >> Point.first >> Point.second;
            Farm.emplace(Point,true);
        }

        // DFS를 통해 방문하지 않은 곳을 찾아 무리를 탐색
        // 심어진 배추를 모두 방문했을 때 DFS 실행 횟수가 벌레 개수를 의미.
        int WarmCount = 0;
        for(pair<pair<int,int>, bool> FarmValue : Farm)
        {
            if(FarmValue.second && false == Visited[FarmValue.first])
            {
                DFS(FarmValue.first);
                WarmCount++;
            }
        }

        cout << WarmCount << "\n";
    }

    return 0;
}