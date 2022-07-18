    bool allWords(int sr, int sc, int idx, string &str, vector<vector<char> >& board){
        
        if(sr < 0 || sc < 0 || sr >= board.size() || sc >= board[0].size() || str[idx] != board[sr][sc])
            return false;
        
        if(idx == str.length()-1)
            return board[sr][sc] == str[idx];
            
        char curr = board[sr][sc];
        board[sr][sc] = '#';
        
        bool found =allWords(sr-1, sc, idx+1, str, board) ||
        
                    allWords(sr-1, sc+1, idx+1, str, board) || 
                    
                    allWords(sr, sc+1, idx+1, str, board) || 
                    
                    allWords(sr+1, sc+1, idx+1, str, board) ||
  
                    allWords(sr+1, sc, idx+1, str, board) ||
 
                    allWords(sr+1, sc-1,idx+1, str, board) || 
                    
                    allWords(sr, sc-1, idx+1, str, board) ||
   
                    allWords(sr-1, sc-1, idx+1, str, board) ;
                        
        
         board[sr][sc] = curr;
        
        return found;
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<string> res;
	    for(int i = 0; i < dictionary.size(); i++){
	        string str = dictionary[i];
	        bool isFound = false;
	        for(int p = 0; p < board.size(); p++){
	            for(int q = 0; q < board[0].size(); q++){
	                if(board[p][q] == str[0]){
	                    if(allWords(p, q, 0, str, board))
	                       {
	                           isFound = true;
	                           res.push_back(str);
	                           break;
	                       }
	                }
	            }
	            if(isFound)
	                break;
	        }
	    }
	    return res;
	}
