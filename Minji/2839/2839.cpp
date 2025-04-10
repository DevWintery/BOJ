#include <iostream>
#include <vector>
#include <string>

using namespace std;

int MinCombination(int N)
{
    int Max_Devide_3 = N / 3;
    int Max_Devide_5 = N / 5;

    for(int Count_5 = Max_Devide_5; Count_5 >= 0; Count_5--)
    {
        int Remain = (N - 5 * Count_5);
        if(Remain % 3 == 0)
        {
            return Count_5 + (Remain / 3);
        }
    }
    return -1;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    cin >> N;
    cout << MinCombination(N);    

    return 0;
}