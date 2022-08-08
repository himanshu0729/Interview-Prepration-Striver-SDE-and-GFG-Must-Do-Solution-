   int maxSum = INT_MIN;
    int maxPathSumFromLeaf(Node *root){
        if(root == NULL)
            return INT_MIN;
            
        if(root->left == NULL && root->right == NULL)
            return root->data;
            
        int lsmps = maxPathSumFromLeaf(root->left);
        int rsmps = maxPathSumFromLeaf(root->right);
        
        if(root->left != NULL && root->right != NULL)
            maxSum = max(maxSum, lsmps + rsmps + root->data);
        
        return max(lsmps, rsmps) + root->data;
        
    }
    int maxPathSum(Node* root)
    {
        int res = maxPathSumFromLeaf(root);
        if(root->left == NULL || root->right == NULL){
            return max(maxSum, res);
        }
        return maxSum;
    }
