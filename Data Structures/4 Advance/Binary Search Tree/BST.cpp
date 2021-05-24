#include <iostream>

class BST
{
    struct Node
    {
        int data;
        Node *left_child;
        Node *right_child;
    };
    
    Node *root;

    Node *insertion(Node* root, int data)
    {
        if (root == NULL)
        {
            root = new Node();
            root->data = data;
            root->left_child = NULL;
            root->right_child = NULL;
        }

        else if (data <= root->data)
        {
            root->left_child = insertion(root->left_child, data);
        }
        
        else
        {
            root->right_child = insertion(root->right_child, data);
        }
        
        return root;
    }

    Node *deletion(Node *root, int data)
   {
       // EMPTY 
       if (root == NULL)
       {
           return root;
       }

       // DATA IS SMALLER 
       else if(data < root->data)
       {
           root->left_child = deletion(root->left_child, data);                      
       }
       
       // DATA IS GREATER
       else if(data > root->data)
       {
           root->right_child = deletion(root->right_child, data);
       }

       // DELETION 
       else
       {
           // LEAF NODE
           if (root->left_child == NULL and root->right_child == NULL)
           {
               delete root;
               root = NULL;
               return NULL;
           }

           // ONE CHILD
           else if(root->left_child == NULL)  // NO LEFT CHILD
           {
               Node *temp_node = root;
               root = root->right_child;
               delete temp_node;
               return root;
           }

           else if (root->right_child == NULL)  // NO RIGHT CHILD
           {
               Node *temp_node = root;
               root = root->left_child;
               delete temp_node;
               return root;
           }
           
           // BOTH CHILD
           else
           {
               Node *smallest_right_child = find_min(root->right_child);
               root->data = smallest_right_child->data;
               delete smallest_right_child;
           }   
       }
       
       return root;
   }

    Node *find_min(Node* root)
    {
        if (root == NULL)
        {
            return NULL;        
        }

        else if (root->left_child == NULL)
        {
            return root;
        }

        else
        {
            return find_min(root->left_child);
        }
    }

    Node *find_max(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        else if (root->right_child == NULL)
        {
            return root;
        }

        else
        {
            return find_max(root->right_child);
        }
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

    void inorder_display(Node *root)
    {
        if (root==NULL)
        {
            return;
        }
        inorder_display(root->left_child);
        std::cout<<root->data<<" ";
        inorder_display(root->right_child);
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

    void destroy_tree(Node *root)
    {
        if (root != NULL)
        {
            destroy_tree(root->left_child);
            destroy_tree(root->right_child);
            delete root;
        }
    } 
    
    public:

    BST()
    {
        root = NULL;
    }

    void insert(int data)
    {
        root = insertion(root, data);
        return;
    }

    void remove(int data)
    {
        deletion(root, data);
    }

    void preorder()
    {
        preorder_display(root);
        std::cout<<"\n";
    }

    void inorder()
    {
        inorder_display(root);
        std::cout<<"\n";
    }

    void postorder()
    {
        postorder_display(root);
        std::cout<<"\n";
    }

    int min()
    {
        return find_min(root)->data;
    }

    int max()
    {
        return find_max(root)->data;
    }

    ~BST()
    {
        destroy_tree(root);
    }

};


int main()
{ 
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.preorder();
    t.inorder();
    t.postorder();
    std::cout<<"Minimum: \t"<<t.min()<<"\n";
    std::cout<<"Maximum: \t"<<t.max()<<"\n";
    t.remove(25);
    t.inorder();

    return 0;
}
