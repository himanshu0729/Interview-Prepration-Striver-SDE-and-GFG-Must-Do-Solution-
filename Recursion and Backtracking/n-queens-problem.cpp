========================= gfg solution 

    bool isValid(int row, int col, vector<vector<int>> &chees){
        for(int i = 0; i < row; i++){
            if(chees[i][col] == 1)
                return false;
        }
        
        int i = row, j = col;
        while(i >= 0 && j >= 0){
            if(chees[i][j] == 1)
                return false;
            i--;
            j--;
        }
        
        i = row, j = col;
        while(i >= 0 && j < chees.size()){
            if(chees[i][j] == 1)
                return false;
            i--;
            j++;
        }
        
        return true;
    }
    
    void placeQueen(int row, vector<vector<int>> &chees, vector<vector<int>> &res, unordered_map<int, int> &mp){
        
        if(row == chees.size()){
            vector<int> temp;
            for(int i = 0; i < chees.size(); i++){
                temp.push_back(mp[i] + 1);
            }
            res.push_back(temp);
            return;
        }
        
        for(int col = 0; col < chees.size(); col++){
            
            if(isValid(row, col, chees)){
                mp[col] = row;
                chees[row][col] = 1;
                placeQueen(row+1, chees, res, mp);
                chees[row][col] = 0;
                mp.erase(col);                
            }

            
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> chees(n, vector<int>(n, 0));
        vector<vector<int>> res;
        unordered_map<int, int> mp;
        placeQueen(0, chees, res, mp);
        sort(res.begin(), res.end());
        return res;
    }

=============================== leetcode solution 

    bool isValid(int row, int col, vector<string> &cheesBoard){
        //check top 
        for(int i = row-1; i >= 0; i--){
            if(cheesBoard[i][col] == 'Q')
                return false;
        }
        // top-left
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if(cheesBoard[i][j] == 'Q')
                return false;
        }
        
        // top-right
        for(int i = row-1, j = col+1; i >= 0 && j < cheesBoard.size(); j++, i--){
            if(cheesBoard[i][j] == 'Q')
                return false;
        }
        return true;
    }
   
    void nQueens(vector<string> &cheesBoard, int row, vector<vector<string>> &res){
        if(row == cheesBoard.size()){
            vector<string> temp;
            for(auto str : cheesBoard)
                temp.push_back(str);
            res.push_back(temp);
            return;
        }
        for(int col = 0; col < cheesBoard.size(); col++){
            if(isValid(row, col, cheesBoard)){
                cheesBoard[row][col] = 'Q';
                nQueens(cheesBoard, row+1, res);
                cheesBoard[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string str = "";
        for(int i = 0; i < n; i++)
            str += '.';
        vector<string> cheesBoard(n, str);
        nQueens(cheesBoard, 0, res);
        return res;
    }
