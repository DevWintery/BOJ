#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> coords(N);
    for(int i = 0; i < N; i ++)
    {
        cin >> coords[i].first;
        coords[i].second = i;
    }

    sort(coords.begin(), coords.end());

    vector<int> result(N);
    int rank = 0;
    for(int i = 0; i < N; i ++)
    {
        //이미 오름차순 처리 되어있으므로 값이 다르면 무조건 현재값은 이전 값 보다 크다.
        if(i > 0 && coords[i].first != coords[i - 1].first)
        {
            rank ++;
        }

        result[coords[i].second] = rank;
    }

    for(int i : result)
        cout << i << ' ';

    return 0;
}