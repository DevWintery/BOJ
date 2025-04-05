#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void solve()
{
    multiset<int> mts;

    int k;
    cin >> k;

    for(int i = 0; i < k; i ++)
    {
        char command;
        cin >> command;

        int number;
        cin >> number;

        if(command == 'I')
        {
            mts.insert(number);
        }

        else if(command == 'D' && !mts.empty())
        {
            if(number == 1)
            {
                auto it = mts.end();
                mts.erase(--it);
            }
            else if(number == -1)
            {
                mts.erase(mts.begin());
            }
        }
    }

    if(mts.empty() == false)
    {
        auto it = mts.end();

        cout << *(--it) << ' ' << *mts.begin() << '\n';
    }
    else
    {
        cout << "EMPTY" << '\n';
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