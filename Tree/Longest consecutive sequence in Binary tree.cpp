    int len = INT_MIN;
    void longest(Node *root, int height){
        
        len = max(len, height);
        if(root->left){
            if(root->data + 1 == root->left->data){
                longest(root->left, height+1);
            }else 
                longest(root->left, 0);
        }
        
        if(root->right) {
            if(root->data + 1 == root->right->data){
                longest(root->right, height + 1);
            }else 
                longest(root->right, 0);
        }
    }
    
    void longestMethod2(Node *root, int expectedVal, int currLen, int &maxLen){
        
        if(root == NULL)
            return;
            
        if(root->data == expectedVal)
            currLen++;
        else 
            currLen = 1;
            
        maxLen = max(maxLen, currLen);
        
        longestMethod2(root->left, root->data + 1, currLen, maxLen);
        longestMethod2(root->right, root->data + 1, currLen, maxLen);
        
    }
    int longestConsecutive(Node* root)
    {
        //  longest(root, 0);
        //  if(len == 0)
        //     return -1;
        //  return len + 1;
        
        int res = 0;
        longestMethod2(root, root->data + 1, 0, res);
        if(res <= 1)
            return -1;
        return res;
    }
