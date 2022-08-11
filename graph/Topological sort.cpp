Solution 1 => Using Dfs 

	void dfs(int start, vector<int> adj[], vector<bool> &visited, stack<int> &eachEleOrder){
	    visited[start] = true;
	    
	    for(int adjacent : adj[start]){
	        if(visited[adjacent] == false){
	            dfs(adjacent, adj, visited, eachEleOrder);
	        }
	    }
	    
	    eachEleOrder.push(start);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> res;
	   stack<int> eachEleOrder;
	   vector<bool> visited(V, false);
	   for(int i = 0; i < V; i++){
	       if(visited[i] == false){
	           dfs(i, adj, visited, eachEleOrder);
	       }
	   }
	    
	   while(eachEleOrder.size() > 0){
	       res.push_back(eachEleOrder.top());
	       eachEleOrder.pop();
	   }
	   return res;
  }

Solution 2 => Using Bfs 

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> ans;
	   vector<int> indegree(V, 0);
	   for(int i = 0; i < V; i++){
	       for(int adjacent: adj[i]){
	           indegree[adjacent]++;
	       }
	   }
	   
	   queue<int> topSort;
	   for(int i = 0; i < V; i++){
	       if(indegree[i] == 0){
	           topSort.push(i);
	       }
	   }
	   
	   
	   while(topSort.size() > 0){
	       int t = topSort.front();
	       topSort.pop();
	       ans.push_back(t);
	       
	       for(int adjacent: adj[t]){
	           indegree[adjacent]--;
	           if(indegree[adjacent] == 0){
	               topSort.push(adjacent);
	           }
	       } 
	   }
	   return ans;
	}
