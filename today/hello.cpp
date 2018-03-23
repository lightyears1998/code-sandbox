#include <bits/stdc++.h>
using namespace std;
using LL = long long;
 
const int maxN = 1000100;

bool digit[maxN][10]; 
LL nonrep[maxN];
 
bool check(LL num)
{   
    while (num) {
        int cur = num%10;
        if (digit[cur]) return false;
        digit[cur] = true;
        num /= 10;
    }
    return true;
}
 
void build()
{   
    LL base = 1, gap = 0, tail = 0;
    while (tail<maxN) {
        for (int i=1; i<10 && tail<maxN; ++i)
        {
            for (int j=0; j<=gap && tail<maxN; ++j) 
            {
                if (check(i, nonrep[j]))
                    nonrep[++tail] = i*base+nonrep[j];
            }
        } 
        base *= 10, gap = tail;
    }
}
 
int main()
{   
    build();
     
    int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        printf("%lld\n", nonrep[n]);
    }
}
