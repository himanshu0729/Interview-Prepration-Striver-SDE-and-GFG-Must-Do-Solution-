    bool allPartition(int idx, string str, unordered_map<string, bool> &mp, vector<int> &dp){
        
        if(idx == str.length()){
            return true;
        }
        
        if(dp[idx] != -1)
            return dp[idx];
        
        for(int par = idx; par < str.length(); par++){
            string temp = str.substr(idx, par-idx+1);
            if(mp.find(temp) != mp.end()){
                if(allPartition(par+1, str, mp, dp))
                    return dp[idx] = true;
            }
        }
        
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict){
        unordered_map<string, bool> mp;
        for(string &str: wordDict)
            mp[str] = true;
        
        vector<int> dp(s.length() + 1, -1);
        return allPartition(0, s, mp, dp);
    }
