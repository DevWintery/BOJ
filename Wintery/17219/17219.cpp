#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    unordered_map<string, string> map;

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; ++i)
    {
        pair<string, string> p;
        cin >> p.first;
        cin >> p.second;

        map.insert(p);
    }

    for(int i = 0; i < M; ++i)
    {
        string url;
        cin >> url;

        cout << map[url] << '\n';
    }

    return 0;
}