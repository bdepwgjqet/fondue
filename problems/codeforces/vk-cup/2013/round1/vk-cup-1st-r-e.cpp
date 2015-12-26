/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/14/2012 09:42:12 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define N 100101
#define MAXM 1000010
#define X 11

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

int num[X],isp[N],plist[N],top,len,D[9],cnt[N],iden[N];

int find(int x)
{
	int l,r,m;
	for(l=0,r=top-1; l<=r; )
	{
		m=(l+r)>>1;
		if(plist[m]<x)
			l=m+1;
		else
			r=m-1;
	}
	return l;
}

void init()
{
	int i,j;
	top=0; D[0]=1;
	for(i=1; i<10; i++)
		D[i]=D[i-1]*10;
	for(i=0; i<N; i++)	
		isp[i]=i;
	for(i=2; i<N; i++)
	{
		if(isp[i]==i)
			plist[top++]=i;
		for(j=0; j<top&&i*plist[j]<N; j++)
		{
			isp[i*plist[j]]=plist[j];
			if(i%plist[j]==0)
				break;
		}
	}
	memset(cnt,0,sizeof(cnt));
	for(i=2; i<N; i++)
	{
		if(i%10==0)
		{
			for(j=i; j<i+10; j++)
				if(isp[j]==j)
					cnt[i]++;
			i+=9;
		}
	}
	for(i=0; i<N; i++)
		iden[i]=find(i);
}

int get_mat(int x)
{
	int ret=0,y=x,i;
	for(; y; )
		ret++,y/=10;
	for(i=ret; i>0; i--)
	{
		num[i]=x%10,x/=10;
	}
	return ret;
}

int dfs(int id)
{
	int x=num[id]*D[len-id+1],i,y=(num[id]+1)*D[len-id+1],ret=0,t,u,j;
	i=iden[x];
	if(id==len)
		return cnt[x];
	for(; plist[i]<y; i++)
	{
		t=plist[i]%D[len-id+1];
		for(j=len; j>=id; j--)
			u=t%10,num[j]*=10,num[j]+=u,t/=10;
		ret+=dfs(id+1);
		t=plist[i]%D[len-id+1];
		for(j=len; j>=id; j--)
			u=t%10,num[j]/=10;
	}
	return ret;
}

int solve(int x)
{
	int ret,i;
	len=get_mat(x);
	num[1]=x;
	if(len==1)	
		return isp[x]==x;
	ret=dfs(2);
	return ret;
}

int main()
{
	int t,n;
	init();
	scanf("%d",&t);
	for(; t--; )
	{
		scanf("%d",&n);
		printf("%d\n",solve(n));
	}
	return 0;
}
