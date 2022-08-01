   vector<int> verticalOrder(Node *root)
    {
        vector<int> res;
        if(root == NULL)
            return res;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        map<int, vector<int>> m;
        int minVal = INT_MAX, maxVal = INT_MIN;
        while(q.size() > 0){
            pair<Node*, int> p = q.front();
            Node *temp = p.first;
            int pos = p.second;
            if(pos > maxVal)
                maxVal = pos;
            if(pos < minVal)
                minVal = pos;
            m[pos].push_back(temp->data);
            q.pop();
            if(temp->left != NULL) {
                q.push({temp->left, pos - 1});
            }
            if(temp->right != NULL) {
                q.push({temp->right, pos + 1});
            }
        }
         for(auto it = m.begin(); it != m.end(); it++) {
            for(auto x: m[it->first])
                {
                    res.push_back(x);
                }
        }
        return res;
    }
