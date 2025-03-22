#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


int N, M;
vector<int> Numbers;
bool Visited[8];
vector<int> Sequence;

void GetSequence()
{
    if(Sequence.size() == M)
    {
        for(int Num : Sequence)
        {
            cout << Num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if(false == Visited[i])
        {
            Visited[i] = true;
            Sequence.push_back(Numbers[i]);
            GetSequence();
            Sequence.pop_back();
            Visited[i] = false;
        }
    }
}

int main()
{
    Initialize
    
    cin >> N >> M;
    Numbers.resize(N);

    int Num;
    for(int i = 0; i < N; i ++)
    {
        cin >> Numbers[i];
    }
    sort(Numbers.begin(), Numbers.end());

    GetSequence();
}