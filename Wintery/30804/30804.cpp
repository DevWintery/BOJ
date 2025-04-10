#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int typeCount = 0;
int sum = 0;

int types[10] = {0};

void Add(int index)
{
    types[index] += 1;
    sum += 1;

    if(types[index] - 1 == 0)
    {
        typeCount ++;
    }
}

void Sub(int index)
{
    types[index] -= 1;
    sum -= 1;

    if(types[index] == 0)
    {
        typeCount --;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> friuts(N);
    for(int i = 0; i < N; i ++)
    {
        cin >> friuts[i];
    }

    int start = 0;
    int end = 0;

    int answer = 0;

    Add(friuts[start]);

    while(start < N && end < N)
    {
        if(typeCount <= 2)
        {
            answer = ::max(answer, sum);

            end ++;
            if(end < N)
            {
                Add(friuts[end]);
            }
        }
        else
        {
            start ++;
            if(start < N)
            {
                Sub(friuts[start - 1]);
            }
        }
    }

    cout << answer;

    return 0;
}