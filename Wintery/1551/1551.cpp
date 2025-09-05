#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    
    vector<int> v(N);
    for(int i = 0; i < N - 1; i ++)
    {  
        char ch;
        cin >> v[i] >> ch;
    }
    cin >> v[N - 1];

    for(int i = 0; i < K; i ++)
    {
        for(int j = 0; j < N - 1; j ++)
        {
            v[j] = v[j + 1] - v[j];
        }
        N -= 1;
    }

    for(int i = 0; i < N - 1; i ++)
    {
        cout << v[i] << ',';
    }

    cout << v[N - 1];

    return 0;
}