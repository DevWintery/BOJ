#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long factorial(long long N)
{
    if(N == 0)
        return 1;
        
    return N * factorial(N - 1);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    cout << factorial(N);

    return 0;
}