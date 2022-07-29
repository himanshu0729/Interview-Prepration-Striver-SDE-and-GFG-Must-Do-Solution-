    void width(Node *root, int hl, int widthHL[2]) {
        if(root == NULL)    
            return;
        
        widthHL[0] = min(widthHL[0], hl);
        widthHL[1] = max(widthHL[1], hl);
        
        width(root->left, hl-1, widthHL);
        width(root->right, hl+1, widthHL);
    }
    void dfs(Node *root, int verticalOrder, vector<int> order[]){
        if(root == NULL)
            return;
        order[verticalOrder].push_back(root->data);
        dfs(root->left, verticalOrder-1, order);
        dfs(root->right, verticalOrder+1, order);
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> res;
        if(root == NULL)
            return res;
        int widthHL[2];
        widthHL[0] = INT_MAX;
        widthHL[1] = INT_MIN;
        width(root, 0, widthHL);
        int len = widthHL[1] - widthHL[0] + 1;
        vector<int> verOrder[len];
        
        queue<pair<Node*, int>> q;
        q.push({root, abs(widthHL[0]) });
        while(q.size() > 0) {
            pair<Node*, int> top = q.front();
            Node *temp = top.first;
            int dis = top.second;
            q.pop();
            
            verOrder[dis].push_back(temp->data);
            
            if(temp->left != NULL)
            {
                q.push({temp->left, dis-1});
            }
            if(temp->right != NULL) {
                q.push({temp->right, dis+1});
            }
        }
        
        // Does not work because vertical order may change because it cover first left subtree then right subtree
        // dfs(root, abs(widthHL[0]), verOrder);
        for(int i = 0; i < len; i++) {
            res.push_back(verOrder[i].back());
        }
        
        return res;
    }
