#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<int, vector<int>> Points;
set<int> XPoints;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        pair<int,int> Point;
        cin >> Point.first >> Point.second;
        Points[Point.first].push_back(Point.second);
        XPoints.emplace(Point.first);
    }
    
    for(int X : XPoints)
    {
        auto It = Points.find(X);
        if(It != Points.end())
        {
            sort(It->second.begin(), It->second.end());
            
            for(int Y : It->second)
            {
                cout << X << " " << Y << "\n";
            }
        }
    }

    return 0;
}