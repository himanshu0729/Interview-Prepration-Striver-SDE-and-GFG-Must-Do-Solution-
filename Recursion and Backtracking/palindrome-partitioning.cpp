    bool isPalindrome(int start, int end, string &str){
        while(start < end){
            if(str[start] != str[end])
                return false;
            
            start++;
            end--;
        }
        return true;
    }
    
    void allPartition(int idx, string &str, vector<vector<string>> &res, vector<string> &temp){
        if(idx == str.length()){
            res.push_back(temp);
            return;
        }
        
        for(int i = idx; i < str.length(); i++){
            if(isPalindrome(idx, i, str)){
                temp.push_back(str.substr(idx, i - idx + 1));
                allPartition(i+1, str, res, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        allPartition(0, s, res, temp);
        return res;
    }
