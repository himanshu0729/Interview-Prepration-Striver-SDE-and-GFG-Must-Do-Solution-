    bool nodeToRootPath(Node *root, int val, unordered_map<Node*, int> &path, int level){
        
        if(root == NULL)
            return false;
        
        if(root->data == val){
            path[root] = level;
            return true;
        }
        
        if(nodeToRootPath(root->left, val, path, level+1)){
            path[root] = level;
            return true;
        }
        if(nodeToRootPath(root->right, val, path, level+1)){
            path[root] = level;
            return true;
        }
        
        return false;
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        
       unordered_map<Node*, int> path1, path2;
       nodeToRootPath(root, n1, path1, 0);
       nodeToRootPath(root, n2, path2, 0);
       
       if(path1.size() == 0 || path2.size() == 0)
            return NULL;
       
       int maxLevel = INT_MIN;
       Node *res = NULL;
       for(auto val: path1){
           if(path2.find(val.first) != path2.end()){
               if(maxLevel < val.second){
                   maxLevel = val.second;
                   res = val.first;
               }
           }
       }
       
       return res;
       
    }
