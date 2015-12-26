#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define X 1111
#define N 111

using namespace std;

int mat[N][N],p[X],pl[X],top;

void init()
{
	top=0;
	for(int i=0; i<X; i++)
		p[i]=i;
	for(int i=2; i<X; i++)
	{
		if(p[i]==i)
			pl[top++]=i;
		for(int j=0; j<top&&i*pl[j]<X; j++)
		{
			p[i*pl[j]]=pl[j];
			if(i%pl[j]==0)
				break;
		}
	}
}

string s;

string add(string a,string b)
{
	string ret;
	int add=0;
	for(int i=0; add>0||i<a.length()||i<b.length(); i++)
	{
		int aa,bb;
		if(i<a.length()) aa=a[i]-'0';
		else aa=0;
		if(i<b.length()) bb=b[i]-'0';
		else bb=0;
		int now=aa+bb+add;
		add=now/10,now=now%10;
		ret.push_back(now+'0');
	}
	return ret;
}

void show(int x)
{
	s=string("1");
	for(int i=0; i<x; i++)
		s=add(s,s);
	s[0]--;
	for(int i=s.length()-1; i>=0; i--)
		printf("%c",s[i]);
	puts("");
}

int main()
{
	int n,m;
	init();
	while(scanf("%d%d",&n,&m)+1)
	{
		memset(mat,0,sizeof(mat));
		for(int i=0; i<m; i++)
		{
			int x;
			scanf("%d",&x);
			for(int j=0; pl[j]<=x; j++)
			{
				if(x%pl[j]==0)
				{
					int c=0;
					for(; x%pl[j]==0;)
						x/=pl[j],c++;
					mat[i][j]=c&1;
				}
			}
		}
		int z;
		for(z=0; z<min(m,n); z++)
		{
			int u=-1,v=-1;
			for(int i=z; i<m&&u<0; i++)
				for(int j=z; j<n&&u<0; j++)
					if(mat[i][j])
						u=i,v=j;
			if(u<0) break;
			for(int i=0; i<n; i++)
				swap(mat[z][i],mat[u][i]);
			for(int j=0; j<m; j++)
				swap(mat[j][z],mat[j][v]);
			for(int i=0; i<m; i++)
			{
				if(i==z) continue;
				if(mat[i][z])
					for(int j=z; j<n; j++)
						mat[i][j]^=mat[z][j];
			}
		}
		z=m-z;
		show(z);
	}
	return 0;
}
