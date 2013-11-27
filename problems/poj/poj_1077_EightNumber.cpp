/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/12/2012 09:58:09 AM
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
#define N 400000
#define M 1000010
#define S 400100
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

struct node{ int x,pos,cnt,pre,dir; }q[S];
int vis[N];
char s[10];
char direct[4]={'r','l','u','d'};
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}},ten[11],jie[11];
int num[11];

void init()
{
	ten[0]=1;
	jie[0]=1;
	for(int i=1; i<11; i++)
		ten[i]=ten[i-1]*10;
	for(int i=1; i<11; i++)
		jie[i]=jie[i-1]*i;
}

inline int inboard(int x,int y)
{
	return 0<=x&&x<3&&0<=y&&y<3;
}

inline int get_perm(int x)
{
	int ret=1;
	for(int i=0; i<9; i++)
		num[i]=(x/ten[8-i])%10;
	for(int i=7; i>=0; i--)
	{
		for(int j=i+1; j<9; j++)
		{
			if(num[j]<num[i])
				ret+=jie[8-i];
		}
	}
	return ret;
}

inline void _swap(int a,int b,int &x)
{
	int aa=(x/ten[a-1])%10;
	int bb=(x/ten[b-1])%10;
	x+=bb*ten[a-1]-aa*ten[a-1];
	x+=aa*ten[b-1]-bb*ten[b-1];
}

inline node get_next(int x,int id,int pos)
{
	node ret;
	int nowx=pos/3,nowy=pos%3;
	int nextx=nowx+dir[id][0],nexty=nowy+dir[id][1];
	if(!inboard(nextx,nexty))
	{
		ret.x=-1;
		return ret;
	}
	int nextp=nextx*3+nexty;
	_swap(9-pos,9-nextp,x);
	ret.x=x,ret.pos=nextp;
	return ret;
}

int solve(int st,int pos)
{
	int l,r;
	q[l=r=0].x=st,q[0].pos=pos;
	q[0].cnt=0,q[0].pre=-1;
	memset(vis,0,sizeof(vis));
	vis[get_perm(st)]=1;
	for(; l<=r;)
	{
		node now=q[l++];
		for(int i=0; i<4; i++)
		{
			node next=get_next(now.x,i,now.pos);
			if(next.x<0)
				continue;
			int rank=get_perm(next.x);
			if(vis[rank])
				continue;
			vis[rank]=1;
			q[++r]=next;
			q[r].cnt=now.cnt+1;
			q[r].pre=l-1;
			q[r].dir=i;
			if(next.x==123456780)
				return r;
		}
	}
}

void shownum(int x)
{
	printf("%d\n",x/ten[6]);
	printf("%d\n",(x/ten[3])%ten[3]);
	printf("%d\n",x%ten[3]);
}

void show(int id)
{
	if(q[id].pre==-1)
	{
		return;
	}
	else
		show(q[id].pre);
	printf("%c",direct[q[id].dir]);
}

int main()
{
	init();
	while(scanf("%s",s)!=EOF)
	{
		int now,pos;
		if(s[0]=='x')
			now=0,pos=0;
		else
			now=s[0]-'0';
		for(int i=0; i<8; i++)
		{
			while(1)
			{
				s[0]=getchar();
				if(s[0]==' ')
					continue;
				else
					break;
			}
			now*=10;
			if(s[0]=='x')
				now+=0,pos=i+1;
			else
				now+=s[0]-'0';
		}
		int id=solve(now,pos);
		show(id);
		puts("");
	}
	return 0;
}
