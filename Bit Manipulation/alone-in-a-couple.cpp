    int findSingle(int N, int arr[]){
        int ans = 0;
        for(int i = 0; i < N; i++)
            ans = ans ^ arr[i];
            
        return ans;
    }
