#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int gcd(int p, int q)
{
    if(q == 0) return p;

    return gcd(q, p%q);
}

int main()
{
    Initialize

    int A, B;
    int C, D;

    cin >> A >> B >> C >> D;

    int resA;
    int resB;

    resA = (A * D) + (C * B);
    resB = B * D;
    
    int divisor = gcd(resA, resB);
    
    resA /= divisor;
    resB /= divisor;

    cout << resA << ' ' << resB;

    return 0;
}