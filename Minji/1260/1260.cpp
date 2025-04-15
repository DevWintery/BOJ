#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int MAX_NODE_NUM = 0;
int MAX_EDGE_NUM = 0;
int START_NODE_NUM = 0;

struct Edge
{
    int Node_1 = 0;
    int Node_2 = 0;

    bool IsExistNode(int Node) const
    {
        return (Node == Node_1) || (Node == Node_2);
    }

    int NeighborNode(int Node) const
    {
        if(Node == Node_1)
        {
            return Node_2;
        }
        else if(Node == Node_2)
        {
            return Node_1;
        }
        else
        {
            return -1;
        }
    }
};

vector<Edge> Graph;

vector<int> NeighborNodeList(int NodeNum)
{
    vector<int> Return;

    for(Edge edge : Graph)
    {
        int AnotherNode = edge.NeighborNode(NodeNum);
        if(AnotherNode > 0)
        {
            Return.push_back(AnotherNode);
        }
    }

    sort(Return.begin(), Return.end());
    return Return;
}

void DFS(int NodeNum, vector<bool>& visited)
{
    visited[NodeNum] = true;
    cout << NodeNum << " ";

    vector<int> NeighborNode = NeighborNodeList(NodeNum);
    for(int Neighbor : NeighborNode)
    {
        if(false == visited[Neighbor])
        {
            DFS(Neighbor, visited);
        }
    }
}

void BFS(int NodeNum, vector<bool>& visited)
{
    queue<int> q;
    q.push(NodeNum);
    visited[NodeNum] = true;

    while(false == q.empty())
    {
        int Node = q.front();
        q.pop();
        cout << Node << " ";

        vector<int> NeighborNode = NeighborNodeList(Node);
        for(int Neighbor : NeighborNode)
        {
            if(false == visited[Neighbor])
            {
                visited[Neighbor] = true;
                q.push(Neighbor);
            }
        }

    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> MAX_NODE_NUM >> MAX_EDGE_NUM >> START_NODE_NUM;

    for(int i = 0; i < MAX_EDGE_NUM; i++)
    {
        Edge edge;
        cin >> edge.Node_1 >> edge.Node_2;
        Graph.push_back(edge);
    }

    vector<bool> DFS_Visited;
    DFS_Visited.resize(MAX_NODE_NUM + 1, false);
    DFS(START_NODE_NUM, DFS_Visited);

    cout << "\n";

    vector<bool> BFS_Visited;
    BFS_Visited.resize(MAX_NODE_NUM + 1, false);
    BFS(START_NODE_NUM, BFS_Visited);

    return 0;
}