   long long int optimalKeys(int N){
        if(N < 7)
            return N;
            
        vector<long long int> dp(N+1, 0);
        for(int i = 1; i < 7; i++){
            dp[i] = i;
        }
           
        for(int totalOperation = 7; totalOperation <= N; totalOperation++){
            int paste = 1;
            for(int pasteOperation = 3; pasteOperation < totalOperatoin; pasteOperation++){
                dp[totalOperation] = max(dp[totalOperation], dp[totalOperation-pasteOperation] * (paste+1));
                paste++;
            }
        } 
        
        return dp[N];
    }
