#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll in()
{
    char c=getchar();
    while(!isdigit(c))c=getchar();
    ll x=0;
    while(isdigit(c))
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}

int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}

const int MAX=2000+5;
int a[MAX];
int main()
{
    int n=in(),cnt=0,mi=0x3f3f3f3f;
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        a[i]=in();
        if(a[i]==1)
        {
            cnt++;
            mi=1;
            flag=1;
        }
        if(!flag)
        {
            int m=a[i];
            for(int j=i-1;j>=0;j--)
            {
                m=gcd(a[j],m);
                if(m==1)
                {
                    mi=mi<i-j?mi:i-j;
                    flag=1;
                    goto N;
                }
            }
        }
        N:;
    }
    if(n==cnt)
    {
        printf("%d\n",0);
        return 0;
    }
    if(mi==0x3f3f3f3f)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n",n-cnt+mi-1);

    return 0;
}
