#include <iostream>
#include <stack>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


stack<int> Stack;

int main()
{
    Initialize

    int CommandCount = 0;
    cin >> CommandCount;

    for(int i = 0; i < CommandCount; i++)
    {
        string Command;
        cin >> Command;

        if(Command == "push")
        {
            int X = 0;
            cin >> X;
            Stack.push(X);
        }
        else if(Command == "pop")
        {
            if(Stack.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << Stack.top() << "\n";
                Stack.pop();
            }
        }
        else if (Command == "size")
        {
            cout << Stack.size() << "\n";
        }
        else if (Command == "empty")
        {
            cout << Stack.empty() << "\n";
        }
        else if(Command == "top")
        {
            cout << (Stack.empty() ? -1 : Stack.top()) << "\n";
        }
        else
        {
            continue;
        }
    }
}