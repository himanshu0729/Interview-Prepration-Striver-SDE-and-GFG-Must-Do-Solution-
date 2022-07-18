    void allPaths(int sr, int sc, vector<vector<int>> &mat, vector<string> &res, string temp){
        
        
        if(sr < 0 || sc < 0 || sr >= mat.size() || sc >= mat[0].size() || mat[sr][sc] == 0)
            return;
            
        if(sr == mat.size()-1 && sc == mat.size()-1){
            res.push_back(temp);
            return;
        }
        
        mat[sr][sc] = 0;
        allPaths(sr-1, sc, mat, res, temp+"U");
        mat[sr][sc] = 1;
        
        mat[sr][sc] = 0;
        allPaths(sr+1, sc, mat, res, temp+"D");
        mat[sr][sc] = 1;
        
        mat[sr][sc] = 0;
        allPaths(sr, sc-1, mat, res, temp+"L");
        mat[sr][sc] = 1;
        
        mat[sr][sc] = 0;
        allPaths(sr, sc+1, mat, res, temp+"R");
        mat[sr][sc] = 1;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n){
        vector<string> res;
        // if(m[n-1][n-1] == 0)
        //     return res;
        string temp = "";
        allPaths(0, 0, m, res, temp);
        return res;
    }
