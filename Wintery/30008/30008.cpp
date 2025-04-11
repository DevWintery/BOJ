#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> v(K);
    for(int i = 0; i < K; i ++)
    {
        cin >> v[i];
    }
    
    for(int i : v)
    {
        int grade = i * 100 / N;
        if(0 <= grade && grade <= 4)
            cout << 1 << ' ';
        else if(4 <= grade && grade <= 11)
            cout << 2 << ' ';
        else if(11 <= grade && grade <= 23)
            cout << 3 << ' ';
        else if(23 <= grade && grade <= 40)
            cout << 4 << ' ';
        else if(40 <= grade && grade <= 60)
            cout << 5 << ' ';
        else if(60 <= grade && grade <= 77)
            cout << 6 << ' ';
        else if(77 <= grade && grade <= 89)
            cout << 7 << ' ';
        else if(89 <= grade && grade <= 96)
            cout << 8 << ' ';
        else if(96 <= grade && grade <= 100)
            cout << 9 << ' ';
    }
    
    return 0;
}