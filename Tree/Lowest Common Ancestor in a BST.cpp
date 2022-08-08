Solution 1 => without consider BST

bool nodeToRoot(Node *root, int key, vector<Node*> &res) {
    
    if(root == NULL)
        return false;
        
    if(root->data == key) {
        res.push_back(root);
        return true;
    }
    
    bool ls = nodeToRoot(root->left, key, res);
    if(ls == true)
    {
        res.push_back(root);
        return true;
    }
    bool rs = nodeToRoot(root->right, key, res);
    if(rs == true)
    {
        res.push_back(root);
        return true;
    }
    
    return false;
}
Node* LCA(Node *root, int n1, int n2)
{
   if(root == NULL)
        return NULL;
    
    vector<Node*> pathOfN1;
    nodeToRoot(root, n1, pathOfN1);
    vector<Node*> pathOfN2;
    nodeToRoot(root, n2, pathOfN2);
    
    int n1s = pathOfN1.size();
    int n2s = pathOfN2.size();
    if(n1s == 0 || n2s == 0)
        return NULL;
        
    int d = 0;
    if(n1s > n2s) {
        d = n1s-n2s;
        int i = d, j = 0;
        while(i < n1s && j < n2s && pathOfN1[i] != pathOfN2[j]){
            i++;
            j++;
        }
        if(i < n1s)
            return pathOfN1[i];
    }else {
        d = n2s-n1s;
        int i = 0, j = d;
        while(i < n1s && j < n2s && pathOfN1[i] != pathOfN2[j]){
            i++;
            j++;
        }
        if(i < n1s)
            return pathOfN1[i];
    }
    return NULL;
}

Solution 2 => Using BST

Node* LCA(Node *root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    
    if(n1 > root->data && n2 > root->data) {
        return LCA(root->right, n1, n2);
    }
    
    else if(n1 < root->data && n2 < root->data){
        return LCA(root->left, n1, n2);
    }
    
    else 
        return root;
}
