/*
Depth First Traversals: 
(a) Inorder (Left, Root, Right) : 4 2 5 1 3 
(b) Preorder (Root, Left, Right) : 1 2 4 5 3 
(c) Postorder (Left, Right, Root) : 4 5 2 3 1
*/

#include <iostream>

class BinaryTree
{
    struct Node
    {
        int data;
        Node *left_child;
        Node *right_child;
    };

    Node *root;

    Node *last_right_node(Node *root)
    {
        Node *parent_node = root;

        if ((root->right_child)->right_child == NULL)
        {
            return parent_node;
        }        

        return last_right_node(root->right_child);
    }

    Node *appendage(Node *root, int data)
    {
        if (root == NULL)
        {
            root = new Node();
            root->data = data;
            root->left_child = NULL;
            root->right_child = NULL;
            return root;
        }

        else if (root->left_child == NULL and root->right_child == NULL)
        {
            root->left_child = appendage(root->left_child, data);
        }

        else if (root->left_child != NULL and root->right_child == NULL)
        {
            root->right_child = appendage(root->right_child, data);
        }

        else
        {
            root->left_child = appendage(root->left_child, data);
        }

        return root;
    }

    Node *deletion(Node *root, int data)
    {
        if (root == NULL)
        {
            return root;
        }

        else if (data != root->data)
        {
            root->left_child = deletion(root->left_child, data);
            root->right_child = deletion(root->right_child, data);
        }

        else
        {
            if (root->left_child == NULL && root->right_child == NULL)
            {
                delete root;
                return NULL;
            }

            else if (root->left_child == NULL)
            {
                Node *temp_node = root;
                root = root->right_child;
                delete temp_node;
            }

            else if (root->right_child == NULL)
            {
                Node *temp_node = root;
                root = root->left_child;
                delete temp_node;
            }

            else
            {
                // PARENT NODE OF LAST CHILD
                Node *temp_node = last_right_node(root);
                Node *leaf_node = temp_node->right_child;
                std::cout<<temp_node->data<<"\n"<<leaf_node->data<<"\n";
                temp_node->right_child = NULL;
                leaf_node->left_child = root->left_child;
                leaf_node->right_child = root->right_child;

                root = leaf_node;

                std::cout<<root->data<<"\n";
            }
        }        
    
        return root;
    }
    
    void inorder_display(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder_display(root->left_child);
        std::cout<<root->data<<" ";
        inorder_display(root->right_child);
    }

    void preorder_display(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        std::cout<<root->data<<" ";
        preorder_display(root->left_child);
        preorder_display(root->right_child);
    }

    void postorder_display(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder_display(root->left_child);
        postorder_display(root->right_child);
        std::cout<<root->data<<" ";
    }

    Node *destroy_tree(Node *root)
    {
        if (root != NULL)
        {
            destroy_tree(root->left_child);
            destroy_tree(root->right_child);
            delete root;
        }
        return root;
    }


    public:

    BinaryTree()
    {
        root = NULL;
    }

    void append(int data)
    {
        root = appendage(root, data);
    }

    void remove(int data)
    {
        root = deletion(root,data);
    }

    void inorder()
    {
        inorder_display(root);
        std::cout<<"\n";
    }

    void preorder()
    {
        preorder_display(root);
        std::cout<<"\n";
    }

    void postorder()
    {
        postorder_display(root);
        std::cout<<"\n";
    }

    ~BinaryTree()
    {
        destroy_tree(root);
    }
};

int main()
{
    BinaryTree b;

    b.append(1);
    b.append(2);
    b.append(3);
    b.append(4);
    b.append(5);
    
    b.inorder();
    b.preorder();
    b.postorder();

    b.remove(1);

    b.inorder();

    return 0;
}