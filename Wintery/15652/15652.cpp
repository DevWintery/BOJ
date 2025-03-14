#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

int N, M;

void dfs(vector<int> v, int start)
{
    if(v.size() == M)
    {
        for(int i = 0; i < v.size(); ++i)
            cout << v[i] << ' ';
        cout << '\n';

        return;
    }

    for(int i = start; i < N; ++i)
    {
        v.push_back(i + 1);
        dfs(v, i);
        v.pop_back();
    }
}

int main()
{
    Initialize
    cin >> N >> M;

    vector<int> v;
    dfs(v, 0);

    return 0;
}