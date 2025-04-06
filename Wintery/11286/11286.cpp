#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct Element
{
    int X;
    bool IsNagetive;
};

struct XGrater
{
    constexpr bool operator()(const Element& _Left, const Element& _Right) const
    {
        if(_Left.X == _Right.X)
        {
            return _Right.IsNagetive;
        }

        return _Left.X > _Right.X;
    }
};

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<Element, vector<Element>, XGrater> q;

    int N;
    cin >> N;

    for(int i = 0; i < N; i ++)
    {
        int x;
        cin >> x;
        
        if(x == 0)
        {
            if(!q.empty())
            {
                bool isNegative = q.top().IsNagetive;
                int x = q.top().X; q.pop();
                if(isNegative)
                {
                    x = -x;
                }
                cout << x << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else
        {
            bool isNagetive = false;
            if(x < 0)
                isNagetive = true;
    
            q.push({::abs(x), isNagetive});
        }
    }

    return 0;
}