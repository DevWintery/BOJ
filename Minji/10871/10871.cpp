#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A = 0;
    cin >> N >> A;

    vector<int> Sequence;
    for(int i = 0; i < N; i++)
    {
        int X;
        cin >> X;
        Sequence.push_back(X);
    }

    for(int S : Sequence)
    {
        if(S < A)
        {
            cout << S << " ";
        }
    }

    return 0;
}