#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    unordered_map<int, bool> map;

    for(int i = 1; i <= 20; ++i)
    {
        map[i] = false;
    }

    int M;
    cin >> M;

    for(int i = 0; i < M; ++i)
    {
        string str;
        cin >> str;

        if(str == "empty")
        {
            map.clear();
            continue;
        }
        else if(str == "all")
        {
            for(int i = 1; i <= 20; ++i)
            {
                map[i] = true;
            }
            continue;
        }

        int x;
        cin >> x;
        
        if(str == "add")
        {
            map[x] = true;
        }
        else if(str == "check")
        {
            cout << (map[x] ? 1 : 0) << '\n';
        }
        else if(str == "remove")
        {
            map[x] = false;
        }
        else if(str == "toggle")
        {
            map[x] = !map[x];
        }
    }

    return 0;
}