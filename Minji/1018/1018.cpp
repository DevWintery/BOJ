#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

char Board[51][51];

// (0, 0)은 FirstColor 이다.
int CheckChangeSquare(int StartX, int StartY, char FirstColor)
{ 
    int Result = 0;

    for(int Y = StartY; Y < StartY + 8; Y++)
    {
        for(int X = StartX; X < StartX + 8; X++)
        {
            if((X + Y) % 2 == 0)
            {
                if(FirstColor != Board[Y][X])
                {
                    Result++;
                }
            }
            else if (FirstColor == Board[Y][X])
            {
                Result++;
            }
        }
    }

    return Result;
}

int main()
{
    Initialize

    int N, M = 0;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> Board[i][j];
        }
    }

    int MinChangeCount = INT_MAX;
    for(int Y = 0; Y < N - 7; Y++)
    {
        for (int X = 0; X < M - 7; X++)
        {
            int Count = min(CheckChangeSquare(X, Y, 'W'), CheckChangeSquare(X, Y, 'B'));
            MinChangeCount = min(MinChangeCount, Count);
        }
    }

    cout << MinChangeCount;
}