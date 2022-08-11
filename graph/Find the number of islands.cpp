    void dfs(int sr, int sc,vector<vector<char>>& grid){
        if(sr < 0 || sc < 0 || sr >= grid.size() || sc >= grid[0].size() || grid[sr][sc] == '0')
            return;
            
        grid[sr][sc] = '0';
        
        dfs(sr-1, sc, grid);
        dfs(sr-1, sc+1, grid);
        dfs(sr, sc+1, grid);
        dfs(sr+1, sc+1, grid);
        dfs(sr+1, sc, grid);
        dfs(sr+1, sc-1, grid);
        dfs(sr, sc-1, grid);
        dfs(sr-1, sc-1, grid);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        
        return count;
    }
