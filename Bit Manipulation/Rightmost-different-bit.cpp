    int posOfRightMostDiffBit(int m, int n)
    {
        int k = m ^ n;
        if(k == 0)
            return -1;
        return log2(k & ~(k-1)) + 1;
    }
