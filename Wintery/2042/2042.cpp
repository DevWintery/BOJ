#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SegmentTree
{
public:
    long long n;
    vector<long long> tree;

    SegmentTree(const vector<long long>& numbers):
        n(numbers.size())
    {
        tree.resize(n * 4);
        Build(numbers, 1, 0, n - 1);
    }

    void Build(const vector<long long>& numbers, int node, int l, int r)
    {
        if(l == r)
        {
            tree[node] = numbers[l];
            return;
        }

        int mid = (l + r) / 2;

        Build(numbers, node * 2, l, mid);
        Build(numbers, node * 2 + 1, mid + 1, r);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void Update(int node, int l , int r, int index, long long number)
    {
        if(index < l || r < index)
        {
            return;
        }

        if(l == r)
        {
            tree[node] = number;
            return;
        }

        int mid = (l + r) / 2;
        
        Update(node * 2, l, mid, index, number);
        Update(node * 2 + 1, mid + 1, r, index , number);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long Query(int node, int l, int r, int b, int c)
    {
        if(r < b || c < l)
        {
            return 0;
        }
        
        if(b <= l && r <= c)
        {
            return tree[node];
        }

        int mid = (l + r) / 2;
        return Query(node * 2, l, mid, b, c) + Query(node * 2 + 1, mid + 1, r, b, c);
    }
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<long long> numbers(N);
    for(int i = 0; i < N; i ++)
    {
        cin >> numbers[i];
    }

    SegmentTree tree(numbers);

    for(int i = 0; i < M + K; i ++)
    {
        int a;
        long long b, c;
        cin >> a >> b >> c;

        if(a == 1)
        {
            tree.Update(1, 0, N - 1, b - 1, c);
        }
        else if(a == 2)
        {
            cout << tree.Query(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}