#include <iostream>

struct Node
{
    int data;
    Node *left_child;
    Node *right_child;
};

class BST
{
    Node *root;

    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            root = new Node;
            root->data = data;
            root->left_child = NULL;
            root->right_child = NULL;
        }
        else if(root->data <= data)
        {
            root->left_child = insert(root->left_child, data);
        }
        else
        {
            root->right_child = insert(root->right_child, data);
        }
        return root;
    }

    void inorder(Node *root)
    {
        if(root == NULL)
        {
            return;
        }
        inorder(root->left_child);
        std::cout<<root->data<<" ";
        inorder(root->right_child);
    }

    public:

    BST()
    {
        root = NULL;
    }

    void insert(int input)
    {
        root = insert(root, input);
    }

    void inorder()
    {
        inorder(root);
        std::cout<<"\n";
    }
};

int main()
{ BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.inorder();

}
