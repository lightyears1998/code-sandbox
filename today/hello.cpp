#include<bits/stdc++.h>
typedef long long ll;
#define inf 1000000000
using namespace std;

struct jj
{
	ll dz;
	ll jz;
	ll xgjd;
	
	jj()
	{
		dz=-1;
		jz=0;
		xgjd=-1;
	}
}A[1000005];

bool M[105000];

vector<jj> AA;
vector<jj> BB;

bool mark[1050000];

int main()
{
	ll first,L;

	scanf("%lld%lld",&first,&L);
	while(L--)
	{
		ll a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(c!=-1) A[a].xgjd=c;
		else A[a].xgjd=a;
		A[a].dz=a;
		A[a].jz=b;
		
		if(M[abs(b)]!=0)mark[a]=1;
		else M[abs(b)]++;
	}
	
	AA.push_back(A[first]);
	
	while(first!=A[first].xgjd)
	{
		first=A[first].xgjd;
		if(mark[first]==1)BB.push_back(A[first]);
		else AA.push_back(A[first]);
	}

	AA[AA.size()-1].xgjd=-1;
	if(BB.size()>=1)BB[BB.size()-1].xgjd=-1;
	
	ll pp=AA.size();
	for(ll i=0;i<=pp-2;i++)
	{
		AA[i].xgjd=AA[i+1].dz;
	}

	ll g=BB.size();
	for(ll i=0;i<=g-2;i++)
	{
		BB[i].xgjd=BB[i+1].dz;
		
	}
	
	for(int i=0;i<AA.size();i++)
	{
		if(AA[i].xgjd!=-1)printf("%05lld %lld %05lld\n",AA[i].dz,AA[i].jz,AA[i].xgjd);
		else printf("%05lld %lld -1\n",AA[i].dz,AA[i].jz);
	} 
	for(int i=0;i<BB.size();i++)
	{
		if(BB[i].xgjd!=-1)printf("%05lld %lld %05lld\n",BB[i].dz,BB[i].jz,BB[i].xgjd);
		else printf("%05lld %lld -1\n",BB[i].dz,BB[i].jz);
	} 
}
