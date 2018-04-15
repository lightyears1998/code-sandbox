// long long
// 避免在计算加法时溢出 

#include<cstdio>
using namespace std;
const int mod = 1e9+7;
struct matrix
{
    long long m[2][2];
}ans, base;

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
               temp.m[i][j] = ((temp.m[i][j]+a.m[i][k]*b.m[k][j])%mod)%mod;
           } 
        }
    }
    return temp;
}
int quick_pow(int n)
{

    ans.m[0][0] = ans.m[0][1] =ans.m[1][0]= 1;
    ans.m[1][1] = 0;
    
    base.m[1][0]= base.m[1][1] = 0;
    //base.m[0][1]= base.m[1][0] = 0;
    base.m[0][0]=1;
    base.m[0][1]=2;
    while(n)
    {

        if(n&1)
        base = muti(base, ans);
        ans = muti(ans, ans); 
        n >>= 1;
    }
    return base.m[0][0];
}
int main()
{
    int t;
    while(~scanf("%d", &t))
    {
        while(t--)
        {
            int n;
            scanf("%d", &n);
            if(n==1)
            printf("2\n");
            else if(n==2)
            printf("1\n");
            else
            printf("%d\n", quick_pow(n-2));
        }
    }
}
