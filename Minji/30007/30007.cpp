#include <iostream>
#include <vector>

using namespace std;

#define Initialize      ios_base :: sync_with_stdio(false); \
                        cin.tie(NULL); \
                        cout.tie(NULL);


#define DATA_COUNT (3)
struct Data
{
    int A;
    int B;
    int X;
};

int main()
{
    Initialize

    int Count;
    cin >> Count;

    vector<Data> RamenData;
    
    // Input
    for(int i = 0; i < Count; i++)
    {
        Data data;
        cin >> data.A >> data.B >> data.X;
        RamenData.push_back(data);
    }

    // Output
    for(Data data : RamenData)
    {
        cout << (data.A * (data.X - 1)) + data.B << "\n";
    }
}