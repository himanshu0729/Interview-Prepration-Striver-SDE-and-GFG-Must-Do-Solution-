    unsigned int swapBits(unsigned int n)
    {
    	return (n >> 1) & 0x55555555 | (n << 1) & 0xAAAAAAAA;
    }
