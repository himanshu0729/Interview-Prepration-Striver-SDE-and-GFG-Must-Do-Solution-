    int countBitsFlip(int a, int b){
        int n = a ^ b, c = 0;
        if(n == 0)
            return 0;
        while(n != 0){
            c++;
            n = n & (n-1);
        }
        return c;
    }
