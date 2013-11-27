#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#define N 111

using namespace std;

char s1[N],s2[N],tmp[N];
int len,l,m,y[N],match[N],mat[N];

struct node{ string s; int x;
	node(char ss[],int xx)
	{
		s.clear();
		int i=0;
		for(; ss[i]; i++)
			s[i]=ss[i];
		s[i]=0;
		x=xx;
	}
};
vector<node> vec[N];

int cmp(node a,node b){ return a.s<b.s; } 

int check(int u,int v)
{
	for(int i=0; i<l; i++)
	{
		if(s1[u+i]!='?'&&s2[v+i]!='?')
		{
			if(s1[u+i]!=s2[v+i])
				return 0;
		}
	}
	memset(tmp,0,sizeof(tmp));
	for(int i=0; i<l; i++)
	{
		if(s1[u+i]=='?'&&s2[v+i]=='?')
			tmp[i]='a';
		else if(s1[u+i]=='?')
			tmp[i]=s2[v+i];
		else if(s2[v+i]=='?')
			tmp[i]=s1[u+i];
		else
			tmp[i]=s1[u+i];
	}
	return 1;
}

int find(int now)
{
	for(int i=0; i<vec[now].size(); i++)
	{
		int to=vec[now][i].x;
		if(!y[to])
		{
			y[to]=1;
			if(match[to]<0||find(match[to]))
			{
				match[to]=now;
				mat[now]=to;
				return 1;
			}
		}
	}
	return 0;
}

void gao()
{
	for(int i=0; i<m; i++)
		vec[i].clear();
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(check(i*l,j*l))
			{
				vec[i].push_back(node(tmp,j));
			}
		}
	}
	for(int i=0; i<m; i++)
		sort(vec[i].begin(),vec[i].end(),cmp);
	memset(match,-1,sizeof(match));
	int ret=0;
	for(int i=m-1; i>=0; i--)
	{
		memset(y,0,sizeof(y));
		if(find(i))
			ret++;
	}
	if(ret==m)
	{
		string ans=string("");
		for(int i=0; i<m; i++)
		{
			check(i*l,mat[i]*l);
			ans+=string(tmp);
		}
		cout<<ans<<endl;
	}
	else
		puts("IMPOSSIBLE");
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++)
	{
		scanf("%d%s%s",&m,s1,s2);
		printf("Case #%d: ",ca);
		len=strlen(s1);
		l=len/m;
		gao();
	}
	return 0;
}
