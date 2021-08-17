// long decode2(long x, long y, long z);

long decode2(long x, long y, long z)
{
    long tmp = y - z;
    return (tmp * x) ^ (tmp << 31 >> 31);
}