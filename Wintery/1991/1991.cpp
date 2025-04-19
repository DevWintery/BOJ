#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Node
{
public:
    string Value;

    Node* LeftChild;
    Node* RightChild;

public:
    Node(string value):
        Value(value), LeftChild(nullptr), RightChild(nullptr)
    {}
};

class Tree
{
public:
    Tree():
        root(nullptr)
    {}

public:
    void InsertNode(string parent, string left, string right)
    {
        Node* newNode = new Node(parent);
        
        if(root == nullptr)
        {
            root = newNode;
        }

        queue<Node*> nodeQueue;
        nodeQueue.push(root);

        while(!nodeQueue.empty())
        {
            Node* current = nodeQueue.front(); 
            nodeQueue.pop();
            
            if(current->Value == parent)
            {
                if(left != ".")
                {
                    current->LeftChild = new Node(left);
                }

                if(right != ".")
                {
                    current->RightChild = new Node(right);
                }
            }
            else
            {
                if(current->LeftChild != nullptr)
                {
                    nodeQueue.push(current->LeftChild);
                }
                if(current->RightChild != nullptr)
                {
                    nodeQueue.push(current->RightChild);
                }
            }
        }
    }

    void Preorder()
    {
        PreorderRecursive(root);
        cout << '\n';
    }

    void Inorder()
    {
        InorderRecursive(root);
        cout << '\n';
    }

    void Postorder()
    {
        PostorderRecursive(root);
        cout << '\n';
    }

private:
    void PreorderRecursive(Node* node)
    {
        if(node == nullptr)
        {
            return;
        }

        cout << node->Value;
        PreorderRecursive(node->LeftChild);
        PreorderRecursive(node->RightChild);
    }
    
    void InorderRecursive(Node* node)
    {
        if(node == nullptr)
        {
            return;
        }

        InorderRecursive(node->LeftChild);
        cout << node->Value;
        InorderRecursive(node->RightChild);
    }
    
    void PostorderRecursive(Node* node)
    {
        if(node == nullptr)
        {
            return;
        }

        PostorderRecursive(node->LeftChild);
        PostorderRecursive(node->RightChild);
        cout << node->Value;
    }

private:
    Node* root;
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    Tree* tree = new Tree();

    for(int i = 0; i < N; i ++)
    {
        string root, left, right;
        cin >> root >> left >> right;
        
        tree->InsertNode(root, left, right);
    }

    tree->Preorder();
    tree->Inorder();
    tree->Postorder();

    return 0;
}