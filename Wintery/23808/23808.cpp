#include <iostream>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int main()
{
    Initialize

    int N;
    
    cin >> N;

    for(int i = 0; i < N * 2; ++ i)
    {
        for(int j = 0; j < N; ++j)
            cout << '@';
        for(int j = 0; j < N * 3; ++j)
            cout << ' ';
        for(int j = 0; j < N; ++j)
            cout << '@';
        cout << '\n';
    }

    for(int i = 0; i < N; ++ i)
    {
        for(int j = 0; j < N * 5; ++j)
            cout << '@';
        cout << '\n';
    }

    for(int i = 0; i < N; ++ i)
    {
        for(int j = 0; j < N; ++j)
            cout << '@';
        for(int j = 0; j < N * 3; ++j)
            cout << ' ';
        for(int j = 0; j < N; ++j)
            cout << '@';
        cout << '\n';
    }

    for(int i = 0; i < N; ++ i)
    {
        for(int j = 0; j < N * 5; ++j)
            cout << '@';
        cout << '\n';
    }

    return 0;
}