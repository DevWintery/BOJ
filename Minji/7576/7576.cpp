#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define EmptyTomato (-1)
#define UnripeTomato (0)
#define RipeTomato (1)

int BoxWidth, BoxHeight = 0;

map<pair<int, int>, int> TomatoBox;

queue<pair<int, int>> RipeQueue;

int TotalTomatoCount = 0;
int RipeCount = 0;

vector<pair<int, int>> CheckAroundTomato(pair<int, int> TomatoLoc)
{
    vector<pair<int, int>> ValidAroundTomato = 
    {
        {TomatoLoc.first, TomatoLoc.second - 1},
        {TomatoLoc.first, TomatoLoc.second + 1},
        {TomatoLoc.first - 1, TomatoLoc.second},
        {TomatoLoc.first + 1, TomatoLoc.second}
    };

    return ValidAroundTomato;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> BoxWidth >> BoxHeight;

    for (int Height = 0; Height < BoxHeight; Height++)
    {
        for (int Width = 0; Width < BoxWidth; Width++)
        {
            pair<int, int> Key = {Width, Height};
            int State;
            cin >> State;
            TomatoBox[Key] = State;

            if (State != EmptyTomato)
            {
                if (State == RipeTomato)
                {
                    RipeQueue.push(Key);
                    RipeCount++;
                }
                TotalTomatoCount++;
            }
        }
    }

    int SpendDay = 0;
    while (!RipeQueue.empty())
    {
        int CurrentLevelSize = RipeQueue.size();
        bool Changed = false;

        for (int i = 0; i < CurrentLevelSize; ++i)
        {
            pair<int, int> Ripe = RipeQueue.front();
            RipeQueue.pop();

            for (pair<int, int> Adj : CheckAroundTomato(Ripe))
            {
                auto It = TomatoBox.find(Adj);
                if (It != TomatoBox.end() && It->second == UnripeTomato)
                {
                    It->second = RipeTomato;
                    RipeQueue.push(Adj);
                    RipeCount++;
                    Changed = true;
                }
            }
        }

        if (Changed)
        {
            SpendDay++;
        }
    }

    if (RipeCount < TotalTomatoCount)
    {
        cout << -1;
    }
    else
    {
        cout << SpendDay;
    }
    return 0;
}