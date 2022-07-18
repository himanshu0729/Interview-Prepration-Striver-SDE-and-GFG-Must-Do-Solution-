    bool isValid(int row, int col, vector<vector<char>>& board, char val){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == val)
                return false;
        }
        for(int i = 0; i < 9; i++){
            if(board[i][col] == val)
                return false;
        }
        
        int corRow = 3 * (row/3);
        int corCol = 3 * (col/3);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[corRow+i][corCol+j] == val)
                    return false;
            }
        }
        return true;
    }
    int count1 = 0, count2 = 0;
    vector<vector<char>> resboard;
    void display(vector<vector<char>> board){
        cout << "yes" <<  endl;
    }
    bool solve(int row, int col, vector<vector<char>>& board){
        
        if(row == board.size()){
            return true;
        }
        
        int ncol, nrow;
        if(col == board[0].size()-1){
            nrow = row+1;
            ncol = 0;
        }else {
            nrow = row;
            ncol = col+1;
        }
        
        if(board[row][col] == '.'){
            for(char ch = '1'; ch <= '9'; ch++){
                if(isValid(row, col, board, ch)){
                    board[row][col] = ch;
                    if(solve(nrow, ncol, board))
                        return true;
                    board[row][col] = '.';  
                }
            }
        }else {
            if(solve(nrow, ncol, board))
                return true;
        }
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }

============================== gfg solution 

    bool isValid(int sr, int sc, int val, int grid[N][N]){
        
        for(int i = 0; i < 9; i++){
            if(grid[sr][i] == val)
                return false;
            
            if(grid[i][sc] == val)
                return false;
        }
        
        int br = (sr/3) * 3, bc = (sc/3) * 3;
        for(int i = br; i < br+3; i++){
            for(int j = bc; j < bc+3; j++){
                if(grid[i][j] == val)
                    return false;
            }
        }
        return true;
    }

    bool isPossible(int sr, int sc, int grid[N][N]){
        
        if(sr == N)
            return true;
        
        int nsr, nsc;
        
        if(sc == 8){
            nsc = 0;
            nsr = sr+1;
        }else {
            nsc = sc+1;
            nsr = sr;
        }
        
        if(grid[sr][sc] == 0){
            
            for(int val = 1; val <= 9; val++){
                if(isValid(sr, sc, val, grid)){
                    grid[sr][sc] = val;
                    if(isPossible(nsr, nsc, grid))
                        return true;
                    grid[sr][sc] = 0;
                
                }
            }
        
        }else{
            if(isPossible(nsr, nsc, grid))
                return true;
        }
        
        return false;
        
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        return isPossible(0, 0, grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << grid[i][j] << " ";
            }
        }
    }
