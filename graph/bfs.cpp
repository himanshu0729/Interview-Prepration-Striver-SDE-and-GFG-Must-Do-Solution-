    void bfs(int start, vector<bool> &visited, vector<int> adj[], vector<int> &res){
        
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while(q.size() > 0){
            
            int t = q.front();
            q.pop();
            res.push_back(t);
            
            for(int adjacent: adj[t]){
                if(!visited[adjacent]){
                    q.push(adjacent);
                    visited[adjacent] = true;
                }
                    
            }
        
        }
        
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);
        vector<int> res;
        // for(int i = 0; i < V; i++){
        //     if(!visited[i]){
        //         bfs(i, visited, adj, res);
        //     }
        // }
        bfs(0, visited, adj, res);
        return res;
    }
