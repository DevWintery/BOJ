#include <iostream>
#include <set>
#include <utility>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    int Size;
    cin >> Size;

    int Width = 5;
    int Height = 5;

    set<pair<int, int>> Blank = {{1,0},{2,0},{3,0},
                                {1,1},{2,1},{3,1},
                                {1,3},{2,3},{3,3}};


    for(int Y = 0; Y < Height * Size; Y++)
    {
        for(int X = 0; X < Width * Size; X++)
        {
            pair<int, int> Point = {X / Size, Y / Size};

            if(Blank.count(Point))
            {
                cout << " ";
            }
            else
            {
                cout << "@";
            }
        }
        cout << endl;
    }
}