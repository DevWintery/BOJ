#include <iostream>
#include <vector>
#include <string>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

void solve()
{
    int A, B;
    cin >> A >> B;

    cout << lcm(A, B) << '\n';
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