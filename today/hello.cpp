#include<cstdio>
using namespace std;
const int mod = 1e9+7;

struct matrix
{
    long long m[2][2];
} ans, base;

matrix muti(matrix a, matrix b)
{
    matrix temp;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
        	temp.m[i][j] = 0;
			for(int k=0; k<2; k++) 
			{
			   temp.m[i][j] = (temp.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
			}
        }
    }
    return temp;
}

int quick_pow(int n)
{
    ans.m[0][0] = 1, ans.m[0][1] = 0;
    ans.m[1][0] = 0, ans.m[1][1] = 1;
	
	base.m[0][0] = 0, base.m[0][1] = 1;
    base.m[1][0] = 1, base.m[1][1] = 1;
    while(n)
    {
        if(n&1)
       		ans = muti(ans, base);
       	base = muti(base, base); 
        n >>= 1;
    }
    
    matrix k{2, 1, 0, 0};
    
    return muti(k, ans).m[0][0];
}
int main()
{
    int t;
    while(~scanf("%d", &t))
    {
        while(t--)
        {
            int n; scanf("%d", &n);
            printf("%d\n", quick_pow(n-1));
        }
    }
}
