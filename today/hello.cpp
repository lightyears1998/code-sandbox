#include<cstdio>
#include<algorithm>
  
using namespace std;
  
char a[60][60];
int m,n,an,ex,ey;
int x_1[4]={1,0,-1,0},y_1[4]={0,1,0,-1};
  
int dfs(int x,int y,int sum,int anti)
{  
    int i;
    if(sum>=an){
        return an;
    }
    for(i=0;i<4;++i)
    {  
        if(anti==i)continue;
        if(a[x-x_1[i]][y-y_1[i]]=='#')anti=4;
        else anti=(i+2)%4;
        int x_t=x+x_1[i],y_t=y+y_1[i];
        if(x_t>=m||x_t<0||y_t>=n||y_t<0)continue;
        if(a[x_t][y_t]=='*'){
                while(a[x_t][y_t]=='*'){
                    x_t+=x_1[i];
                    y_t+=y_1[i];
                    if(x_t>=m||x_t<0||y_t>=n||y_t<0)break; 
                }
                if(x_t>=m||x_t<0||y_t>=n||y_t<0)continue;
                if(a[x_t][y_t]=='E')return an=min(an,sum);
                if(a[x_t][y_t]=='#'){
                    a[x_t][y_t]='*';
                    an=min(an,dfs(x_t-x_1[i],y_t-y_1[i],sum+1,anti));
                    a[x_t][y_t]='#';
                    continue;
                }
        }      
        if(a[x_t][y_t]=='E')return an=min(an,sum); 
    }
    return an;
}
  
int main()
{  
    int i,j,sx,sy,ans;
    while(~scanf("%d%d",&n,&m)){
        for(i=0;i<m;++i){
            getchar();
            for(j=0;j<n;++j){
                a[i][j]=getchar();
                if(a[i][j]=='S'){
                    sx=i,sy=j;
                    a[i][j]='*';
                }
                if(a[i][j]=='E')
                    ex=i,ey=j;
            }
        }
        an=16;
        ans=dfs(sx,sy,1,4);
        if(ans<=15)printf("%d\n",ans);
        else printf("-1\n");
    }
}
