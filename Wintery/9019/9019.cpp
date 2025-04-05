#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int L(int x)
{
    int y = x / 1000;
    x %= 1000;
    x = x * 10 + y;
    return x;
}

int R(int x)
{
    int y = x % 10;
    x = 1000 * y + (x - y) / 10;
    return x;
}

int S(int x)
{
    if(x == 0)
        return 9999;

    return x - 1;
}

int D(int x)
{
    return (x * 2) % 10000;
}

void solve()
{
    vector<bool> visit(10000, false);
    string answer = "";

    int A, B;
    cin >> A >> B;

    //숫자, 정답
    queue<pair<int, string>> q;
    q.push({A, answer});

    while(!q.empty())
    {
        int num = q.front().first;
        string str = q.front().second;
        q.pop();

        if(num == B)
        {
            cout << str << '\n';
            return;
        }

        int n_num = 0;

        n_num = D(num);
        if(visit[n_num] == false)
        {
            q.push({n_num, str + 'D'});
            visit[n_num] = true;
        }

        n_num = R(num);
        if(visit[n_num] == false)
        {
            q.push({n_num, str + 'R'});
            visit[n_num] = true;
        }

        n_num = L(num);
        if(visit[n_num] == false)
        {
            q.push({n_num, str + 'L'});
            visit[n_num] = true;
        }

        n_num = S(num);
        if(visit[n_num] == false)
        {
            q.push({n_num, str + 'S'});
            visit[n_num] = true;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}