    int dia = INT_MIN;
    int height(Node *root){
        if(root == NULL)
            return 0;
            
        int ls = height(root->left);
        int rs = height(root->right);
        
        dia = max(dia, ls + rs + 1);
        
        return max(ls, rs) + 1;
    }
    int diameter(Node* root) {
        height(root);
        return dia;
    }
