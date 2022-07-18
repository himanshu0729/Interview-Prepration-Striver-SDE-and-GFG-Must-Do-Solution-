    int toggleBits(int N , int L , int R) {
        int bits1 = 1 << R;
        bits1 = bits1 - 1;
        int bits2 = 1 << (L-1);
        bits2 = bits2 - 1;
        int mask = bits1 ^ bits2;
        
        return N ^ mask;
    }
