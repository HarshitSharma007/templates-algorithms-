//binonial expansion - O(logn): and modulo operation

int power(long long x, unsigned int y, int p)
{
    int res = 1;
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)  //odd y
            res = (res*x) % p;

        // now y must be even
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
