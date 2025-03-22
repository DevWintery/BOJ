#include <iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);



int N, M;
vector<int> v;
set<vector<int>> s;
bool visit[9];

void dfs(int depth, vector<int> ans)
{
    if(depth == M)
    {
        s.insert(::move(ans));
        return;
    }

    for(int i = 0; i < v.size(); ++i)
    {
        if(visit[i] == false)
        {
            visit[i] = true;
            ans.push_back(v[i]);
            dfs(depth + 1, ans);
            ans.pop_back();
            visit[i] = false;
        }
    }
}

int main()
{
    Initialize

    cin >> N >> M;

    for(int i = 0; i < N; i ++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());

    vector<int> ans;
    dfs(0, ans);

    for(vector<int> _v : s)
    {
        for(int i = 0; i < _v.size(); ++i)
        {
            cout << _v[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}