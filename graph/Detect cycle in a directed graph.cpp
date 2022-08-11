    bool dfs(int start, vector<int> adj[], vector<bool> &visited, vector<bool> &samePath){
        
        visited[start] = true;
        samePath[start] = true;
        
        for(int adjacent: adj[start]){
            if(visited[adjacent] == false){
                if(dfs(adjacent, adj, visited, samePath))
                    return true;
            }
            else if(visited[adjacent] == samePath[adjacent])
                return true;
        }
        samePath[start] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> samePath(V, false);
        
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                if(dfs(i, adj, visited, samePath)){
                    return true;
                }
            }
        }
        return false;
    }
