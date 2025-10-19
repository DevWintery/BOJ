#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SegmentTree
{
public:
    int n;
    vector<pair<int, int>> tree;

    SegmentTree(const vector<int>& numbers):
        n(numbers.size())
    {
        tree.resize(numbers.size() * 4);

        Build(1, 0, n - 1, numbers);
    }

    void Build(int node, int left, int right, const vector<int>& numbers)
    {
        if(left == right)
        {
            tree[node] = make_pair(numbers[left], numbers[left]);
            return;
        }

        int mid = (left + right) / 2;

        Build(node * 2, left, mid, numbers);
        Build(node * 2 + 1, mid + 1, right, numbers);

        tree[node] = make_pair(::min(tree[node * 2].first, tree[node * 2 + 1].first),
                                 ::max(tree[node * 2].second, tree[node * 2 + 1].second));
    }

    const pair<int, int> Query(int a, int b, int left, int right, int index)
    {
        //left
        if(right < a || b < left)
        {
            return make_pair(1e9, 0);
        }

        if(a <= left && right <= b)
        {
            return tree[index];
        }

        int mid = (left + right) / 2;
        
        auto l = Query(a, b, left, mid, index * 2);
        auto r = Query(a, b, mid + 1, right, index * 2 + 1);

        return make_pair(::min(l.first, r.first), ::max(l.second, r.second));
    }
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> numbers(N);

    for(int i = 0; i < N; i ++)
    {
        cin >> numbers[i];
    }

    SegmentTree tree(numbers);

    for(int i = 0; i < M; i ++)
    {
        int a, b;
        cin >> a >> b;

        auto result = tree.Query(a - 1, b - 1, 0, N - 1, 1);

        cout << result.first << ' ' << result.second << '\n';
    }

    return 0;
}