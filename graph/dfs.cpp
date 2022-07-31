    void dfs(int start, vector<int> adj[], vector<int> &res, vector<bool> &visited, vector<int> &dis, int len){
        
        res.push_back(start);
        visited[start] = true;
        dis[start] = len;
        
        for(int adjacent: adj[start]){
            if(visited[adjacent] == false){
                dfs(adjacent, adj, res, visited, dis, len+1);
            }
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> res;
        vector<int> dis(V, 0);
        for(int i = 0; i < V; i++){
            if(visited[i] == false)
                dfs(0, adj, res, visited, dis, 0);
        }
        
        return res;
    }
