    Node *tail = NULL;
    void traversal(Node *root){
        
        if(root == NULL)
            return;
            
        traversal(root->left);
            tail->right = root;
            root->left = tail;
            tail = tail->right;
        traversal(root->right);
    }
    Node * bToDLL(Node *root)
    {
        struct Node *head = new Node();
        tail = head;
        traversal(root);
        head = head->right;
        head->left = NULL;
        return head;
    }
