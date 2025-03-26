#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int white = 0;
int blue = 0;

void solve(int y, int x, int size, const vector<vector<int>>& v)
{
    int checker = v[y][x];

    for(int i = y; i < y + size; ++i)
    {
        for(int j = x; j < x + size; ++j)
        {
            if(checker != v[i][j])
                checker = -1;
            
            if(checker == -1)
            {
                int divSize = size / 2;

                solve(y, x, divSize, v);
                solve(y, x + divSize, divSize, v);
                solve(y + divSize, x, divSize, v);
                solve(y + divSize, x + divSize, divSize, v);

                return;
            }
        }
    }

    if(checker == 0)
        ++white;
    else
        ++blue;
}

int main()
{
    Initialize

    int N;
    cin >> N;

    vector<vector<int>> v(N);

    for(int i = 0; i < N; i ++)
    {
        v[i].resize(N);
        for(int j = 0; j < N; j ++)
        {
            cin >> v[i][j];
        }
    }

    solve(0, 0, N, v);

    cout << white << '\n';
    cout << blue;

    return 0;
}