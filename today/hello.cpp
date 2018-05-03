int cal_inv(int a, int p)
{
	int g, x, y; exgcd(a, p, g, x, y);
	return (x%p+p)%p;
}
