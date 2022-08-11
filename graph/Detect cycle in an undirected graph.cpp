Solution 1 => Using Dfs

    bool dfs(int start, vector<int> adj[], int parent, vector<bool> &visited){
    
        visited[start] = true;
        
        for(int adjacent: adj[start]){
            if(visited[adjacent] == false){
                if(dfs(adjacent, adj, start, visited))
                    return true;
            }else if(visited[adjacent] == true && adjacent != parent){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                if(dfs(i, adj, -1, visited))
                    return true;                
            }
        }
        return false;
    }

Solution 2 => Using Bfs 

   bool isCycle(int V, vector<int> adj[]){
        
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                // first => node , second => prev
                queue<pair<int, int>> q;
                q.push({i, -1});
                visited[i] = true;
                
                while(q.size() > 0){
                    
                    pair<int, int> t = q.front();
                    q.pop();
                    
                    for(int adjacent: adj[t.first]){
                        if(visited[adjacent] == false){
                            visited[adjacent] = true;
                            q.push({adjacent, t.first});
                        }else if(visited[adjacent] == true && adjacent != t.second){
                            return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
