#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sum;

void make(int X, int M, int depth)
{
    if(depth == M)
    {
        sum += X;
        return;
    }

    sum += X;

    make(X / 2, M, depth + 1);
    make((X / 2) + (X % 2), M, depth + 1);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X, M;
    cin >> X >> M;

    make(X, M, 0);


    cout << sum;

    return 0;
}