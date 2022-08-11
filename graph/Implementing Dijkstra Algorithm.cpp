    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distance(V, 1e8);
        // vector<int> prev(V, -1);
        distance[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        
        while(pq.size() > 0){
            int dis = (pq.top()).first;
            int ver = (pq.top()).second;
            pq.pop();

            for(vector<int> adjacent: adj[ver]){
                if(adjacent[1] + distance[ver] < distance[adjacent[0]]){
                    // prev[adjacent[0]] = ver;
                    distance[adjacent[0]] = adjacent[1] + distance[ver];
                    pq.push({distance[adjacent[0]], adjacent[0]});
                }
            }
        }
        
        return distance;
    }
