    int countSetBits(int n)
    {
        if(n <= 1)
            return n;
            
        int val = floor(log2(n));
        // return pow(2, val - 1) * val  + (n - pow(2, floor(log2(n))) + 1) + countSetBits(n - pow(2, floor(log2(n))));
        return (1 << (val-1)) * val + (n - (1 << val) + 1) + countSetBits(n - (1 << val));
    }
