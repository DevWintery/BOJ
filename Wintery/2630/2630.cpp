#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

bool IsFilled(int startI, int startJ, vector<vector<int>>& v, int n, bool& isWhite)
{
    int zero = 0;
    int one = 0;
    for(int i = startI; i < startI + n; ++i)
    {
        for(int j = startJ; j < startJ + n; ++j)
        {
            if(v[i][j] == -1)
                return false;

            if(v[i][j] == 0 && one == 0)
                ++zero;
            else if(v[i][j] == 1 && zero == 0)
                ++one;
            else
                return false;
        }
    }
    
    //이미 사용한건 -1로
    for(int i = startI; i < startI + n; ++i)
    {
        for(int j = startJ; j < startJ + n; ++j)
        {
            v[i][j] = -1;
        }
    }

    isWhite = zero > one;
    
    return true;
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

    int div = N;

    int white = 0;
    int blue = 0;
    while(div > 0)
    {
        for(int i = 0; i < N; i += div)
        {
            for(int j = 0; j < N; j += div)
            {
                bool out;
                if(IsFilled(i, j, v, div, out))
                {
                    if(out)
                        ++white;
                    else
                        ++blue;
                }
            }
        }

        div /= 2;
    }

    cout << white << '\n';
    cout << blue;


    return 0;
}