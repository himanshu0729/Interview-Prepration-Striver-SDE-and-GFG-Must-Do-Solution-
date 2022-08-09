    void mirrorTree(Node *root){
        if(root == NULL)
            return;
            
        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        mirrorTree(root->left);
        mirrorTree(root->right);
        
        
    }
    void mirror(Node* node) {
        mirrorTree(node);
    }
