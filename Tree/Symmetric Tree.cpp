    bool isIdentical(Node *l, Node *r) {
        if(l == NULL || r == NULL) 
            return l == r;
            
        if(l->data != r->data) 
            return false;
        
        bool ls = isIdentical(l->left, r->right);
        if(ls == false)
            return false;
        bool rs = isIdentical(l->right, r->left);
        if(rs == false)
            return false;
        
        return true;
    }
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root == NULL)
	        return true;
	   
	    return isIdentical(root, root);
    }
