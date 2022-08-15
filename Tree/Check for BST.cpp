Solution 1 => lay
  
      struct BSTUti {
        int max;
        int min;
        bool bst;
    };
    
    BSTUti BST(Node* root) {
        
        if(root == NULL) {
            BSTUti b;
            b.min = INT_MAX;
            b.max = INT_MIN;
            b.bst = true;
            return b;
        }
        
        BSTUti ls = BST(root->left);
        if(ls.bst == false)
            return ls;
        BSTUti rs = BST(root->right);
        if(rs.bst == false)
            return rs;
            
            
        BSTUti my;
        my.bst = ls.bst && rs.bst;
        my.min = min(min(ls.min, rs.min), root->data);
        my.max = max(max(ls.max, rs.max), root->data);
        
        if(ls.max > root->data)
            my.bst = false;
        if(rs.min < root->data)
            my.bst = false;
            
        
        return my;
    }
    
    bool isBST(Node* root) 
    {
        BSTUti res =  BST(root);
        return res.bst;
    }


solution 2 
  
      bool checkBST(Node *root, int maxEle, int minEle){
        
        if(root == NULL)
            return true;
            
        if(root->data < minEle || root->data > maxEle)
            return false;
            
        return checkBST(root->left, root->data, minEle) && checkBST(root->right, maxEle, root->data);
        
    }
    
    bool isBST(Node* root) 
    {
        return checkBST(root, INT_MAX, INT_MIN);
    }
