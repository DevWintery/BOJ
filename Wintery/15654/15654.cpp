#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int N, M;
vector<int> v;
bool visit[9];

void solve(int depth, vector<int> ans)
{
    if(depth == M)   
    {
        for(int i : ans)
        {
            cout << i << ' ';
        }
        cout << '\n';

        return;
    }

    for(int i = 0; i < v.size(); ++i)
    {
        if(visit[i] == false)
        {
            visit[i] = true;
            ans.push_back(v[i]);
            solve(depth + 1, ans);
            ans.pop_back();
            visit[i] = false;
        }
    }
}

int main()
{
    Initialize

    cin >> N >> M;

    for(int i = 0; i < N; ++i)
    {
        int x = 0;
        cin >> x;
        v.push_back(x);
    }
        
    sort(v.begin(), v.end());

    vector<int> ans;
    solve(0, ans);

    return 0;
}