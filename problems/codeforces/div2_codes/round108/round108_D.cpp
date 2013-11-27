/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/30/2012 11:45:30 AM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char mat[N][N];
int n,m,cnt,tcnt;
vector<int> r;
vector<int> c;

int ok(int r1,int c1,int r2,int c2)
{
	for(int i=r1; i<=r2; i++)
	{
		if(mat[i][c1]=='.'||mat[i][c2]=='.')	return 0;
		if(mat[i][c1]=='#')
			mat[i][c1]='%',tcnt++;
		if(mat[i][c2]=='#')
			mat[i][c2]='%',tcnt++;
	}
	for(int i=c1; i<=c2; i++)
	{
		if(mat[r1][i]=='.'||mat[r2][i]=='.')	return 0;
		if(mat[r1][i]=='#')
			mat[r1][i]='%',tcnt++;
		if(mat[r2][i]=='#')
			mat[r2][i]='%',tcnt++;
	}
	return 1;
}

void reverse(int r1,int c1,int r2,int c2)
{
	for(int i=r1; i<=r2; i++)
	{
		if(mat[i][c1]=='%')
			mat[i][c1]='#';
		if(mat[i][c2]=='%')
			mat[i][c2]='#';
	}
	for(int i=c1; i<=c2; i++)
	{
		if(mat[r1][i]=='%')
			mat[r1][i]='#';
		if(mat[r2][i]=='%')
			mat[r2][i]='#';
	}
}

int solve()
{
	int r1,r2,r3,r4,c1,c2,c3,c4;
	int rs=r.size(),cs=c.size();
	for(int rr1=0; rr1<rs; rr1++)
	for(int rr2=0; rr2<rs; rr2++)
	{
		r1=r[rr1],r2=r[rr2];
		if(r2-r1<2) continue;
		for(int cc1=0; cc1<cs; cc1++)
		for(int cc2=0; cc2<cs; cc2++)
		{
			c1=c[cc1],c2=c[cc2];
			if(c2-c1<2)	continue;
			for(int rr3=0; rr3<rs; rr3++)
			for(int rr4=0; rr4<rs; rr4++)
			{
				r3=r[rr3],r4=r[rr4];
				if(r4-r3<2)	continue;
				for(int cc3=0; cc3<cs; cc3++)
				for(int cc4=0; cc4<cs; cc4++)
				{
					c3=c[cc3],c4=c[cc4];
					if(c4-c3<2)	continue;
					tcnt=0;
					if(ok(r1,c1,r2,c2)&&ok(r3,c3,r4,c4)&&cnt==tcnt)
					{
					//	printf("%d %d\n",tcnt,cnt);
						puts("YES");
						printf("%d %d %d %d\n",r1,c1,r2,c2);
						printf("%d %d %d %d\n",r3,c3,r4,c4);
						return 1;
					}
					reverse(r1,c1,r2,c2);
					reverse(r3,c3,r4,c4);
				}
			}
		}
	}
	return 0;
}

int main()
{
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		r.clear();
		c.clear();
		cnt=0;
		for(int i=1; i<=m; i++)
		{
			scanf("%s",mat[i]+1);
			for(int j=1; j<=n; j++)
				if(mat[i][j]=='#')
					cnt++;
		}
		for(int i=1; i<=m; i++)
			for(int j=1; j+2<=n; j++)
				if(mat[i][j]=='#'&&mat[i][j+1]=='#'&&mat[i][j+2]=='#')
				{
					r.push_back(i);
					break;
				}
		for(int i=1; i<=n; i++)
			for(int j=1; j+2<=m; j++)
				if(mat[j][i]=='#'&&mat[j+1][i]=='#'&&mat[j+2][i]=='#')
				{
					c.push_back(i);
					break;
				}
		if(r.size()>4)
			r.erase(++++r.begin(),----r.end());
		if(c.size()>4)
			c.erase(++++c.begin(),----c.end());
		if(!solve())
			puts("NO");
	}
	return 0;
}
