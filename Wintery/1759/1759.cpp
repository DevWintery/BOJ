#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int L, C;
vector<char> words;

void backtrack(int depth, int a, int b, int idx, string answer)
{
    if(depth == L)
    {
        if(a >= 1 && b >= 2)
        {
            cout << answer << '\n';    
        }
        return;
    }

    for(int i = idx; i < C; i ++)
    {
        char word = words[i];
        if(word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u')
        {
            backtrack(depth + 1, a + 1, b, i + 1, answer + word);
        }
        else
        {
            backtrack(depth + 1, a, b + 1, i + 1, answer + word);
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;

    words.resize(C);
    for(int i = 0; i < C; i ++)
    {
        cin >> words[i];
    }

    sort(words.begin(), words.end());
    backtrack(0, 0, 0, 0, "");

    return 0;
}