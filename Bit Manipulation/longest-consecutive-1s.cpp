    int maxConsecutiveOnes(int N)
    {
        int longestLen = 0, count = 0;
        while(N != 0){
            if(N & 1){
               count++;
            }else {
                longestLen = max(longestLen, count);
                count = 0;
            }
            N = N >> 1;
        }
        longestLen = max(longestLen, count);
        return longestLen;
    }
