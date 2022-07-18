Method 1
  
     unsigned int getFirstSetBit(int n)
    {
        if(n == 0)
            return 0;
        int pos = 1;
        while(n != 0){
            if(n & 1 == 1)
                return pos;
            pos++;
            n = n >> 1;
        }
        return pos;
    }


Method 2 
  
     unsigned int getFirstSetBit(int n)
    {
        return log2(n & ~(n-1)) + 1;
    }
