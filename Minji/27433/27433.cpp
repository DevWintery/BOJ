#include <iostream>
#include <stdint.h>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int64_t FactorialResult = 1;

void Factorial (int Num)
{
    if(Num >= 1)
    {
        FactorialResult *= Num;
    }
    else
    {
        return;
    }

    Factorial(Num - 1);
}

int main()
{
    Initialize

    int FactorialNum;
    cin >> FactorialNum;
    
    FactorialResult = 1;
    Factorial(FactorialNum);

    cout << FactorialResult;
}