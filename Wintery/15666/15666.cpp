#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> sequence;

void dfs(int x)
{
    if (sequence.size() == M)
    {
        for(int num : sequence)
        {
            cout << num << ' ';
        }
        cout << '\n';

        return;
    }

    int prev = -1;

    for(int i = x; i < N; i ++)
    {
        if(numbers[i] == prev)
            continue;

        sequence.push_back(numbers[i]);
        dfs(i);
        sequence.pop_back();

        prev = numbers[i];
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    numbers.resize(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> numbers[i];
    }
    
    sort(numbers.begin(), numbers.end());

    dfs(0);

    return 0;
}