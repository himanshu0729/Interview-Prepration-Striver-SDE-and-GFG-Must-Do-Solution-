    bool checkKthBit(int n, int k)
    {
        int mask = 1 << k;
        if((n & mask) == 0)
            return false;
        return true;
    }
