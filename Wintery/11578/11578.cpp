#include <iostream>
#include <vector>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    int N, M;
    cin >> N >> M;

    vector<int> students(M, 0 );
    for(int i = 0; i < M; ++i)
    {
        int O;
        cin >> O;

        for(int j = 0; j < O; ++j)
        {
            int problem;
            cin >> problem;

            students[i] |= (1 << (problem - 1));
        }
    }

    int problems = (1 << N) - 1;
    int ans = M + 1;

    for(int mask = 1; mask < (1 << M); mask++)
    {
        int teamSize = __builtin_popcount(mask); //1의 개수

        if(teamSize >= ans)
            continue;

        int solve = 0;
        for(int i = 0; i < M; i ++)
        {
            if(mask & (1 << i)) //i번째 학생의 경우
            {
                solve |= students[i];
            }
        }

        if(problems == solve)
            ans = teamSize;
    }

    if(ans > M)
        cout << -1;
    else
        cout << ans;
    
    return 0;
}