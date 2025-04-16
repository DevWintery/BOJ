#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<pair<int, int>> Points;

bool Compare(const pair<int, int>& A, const pair<int,int>& B)
{
    if(A.first == B.first)
    {
        return A.second < B.second;
    }
    return A.first < B.first;
}

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
        Points.push_back(Point);
    }

    sort(Points.begin(), Points.end());

    for(pair<int,int> Point : Points)
    {
        cout << Point.first << " " << Point.second << "\n";
    }

    return 0;
}