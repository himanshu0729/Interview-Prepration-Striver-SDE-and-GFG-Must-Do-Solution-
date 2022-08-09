   int height(Node *root){
        
        if(root == NULL)
            return 0;
            
        int lh = height(root->left);
        if(lh == -1)
            return lh;
        int rh = height(root->right);
        if(rh == -1)
            return rh;
        
        int dif = abs(lh - rh);
        if(dif > 1)
            return -1;
        
        return max(lh, rh) + 1;
        
    }
    bool isBalanced(Node *root)
    {
        if(height(root) == -1)
            return false;
        return true;
    }
