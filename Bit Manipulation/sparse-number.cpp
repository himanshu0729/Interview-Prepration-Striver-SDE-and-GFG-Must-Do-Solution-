    bool isSparse(int n)
    {
        if(n & (n >> 1))
            return false;
        
        return true;
    }
