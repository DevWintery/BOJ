#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);

struct Student
{
    string subject;
    string fruit;
    string color;
};

int main()
{
    Initialize

    vector<Student> v;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        string subject, fruit, color;
        cin >> subject >> fruit >> color;

        v.push_back({subject, fruit, color});
    }

    for(int i = 0 ; i < m; ++i)
    {
        int ans = 0;

        string subject, fruit, color;
        cin >> subject >> fruit >> color;

        for(int j = 0; j < v.size(); ++j)
        {
            if(subject == v[j].subject || subject == "-")
                if(fruit == v[j].fruit || fruit == "-")
                    if(color == v[j].color || color == "-")
                        ans ++;
        }

        cout << ans << '\n';
    }

    return 0;
}