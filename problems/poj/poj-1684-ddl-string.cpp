/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/30/2012 11:00:12 AM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct value{ int v,t; }val[200];
char p[22][N],tmp[10];
char s[5][10]={"DCL","GOTO","INC","DEC","END"};

inline char upper(char x)
{
	if(x>='a'&&x<='z')
		return x+'A'-'a';
	return x;
}

inline int is_letter(char x)
{
	return ('A'<=x&&x<='Z')||('a'<=x&&x<='z');
}

inline int is_number(char x)
{
	return '0'<=x&&x<='9';
}

int equa_c(char x,char y)
{
	return upper(x)==upper(y);
}

int equa(char x[],char y[])
{
	int lx=strlen(x),ly=strlen(y);
	if(lx!=ly)	return 0;
	for(int i=0; i<lx; i++)
		if(!equa_c(x[i],y[i]))
			return 0;
	return 1;
}

int get_kind(char tmp[])
{
	int i;
	for(i=0; i<5; i++)
	{ 
		if(equa(tmp,s[i]))
			return i;
	}
	return 5;
}

void solve0(int id,int i)
{
	char x=p[id][i];
	if(val[x].t!=0)
	{
		val[x].t=0;
		val[x].v=0;
	}
	else
		printf("%d 1\n",id+1);
}

int solve1(int id,int i,int l)
{
	int lab=0;
	char x;
	if(is_letter(p[id][i]))
	{
		x=p[id][i];
		for(i++; i<l&&p[id][i]==' '; i++);
		for(; i<l&&is_number(p[id][i]); i++)
			lab*=10,lab+=p[id][i]-'0';
		if(val[x].v>0&&val[x].t>=0)
		{
			val[x].t++;
			return lab-1;
		}
		else if(val[x].t<0)
		{
			printf("%d 2\n",id+1);
		}
		return id+1;
	}
	else
	{
		for(; i<l&&is_number(p[id][i]); i++)
			lab*=10,lab+=p[id][i]-'0';
		return lab-1;
	}
}

void solve2(int id,int i)
{
	char x=p[id][i];
	if(val[x].t<0)
		printf("%d 2\n",id+1);
	else
		val[x].v++,val[x].t++;
}

void solve3(int id,int i)
{
	char x=p[id][i];
	if(val[x].t<0)
		printf("%d 2\n",id+1);
	else
		val[x].v--,val[x].t++;
}

void solve5(int id,int i,int l,char x)
{
	int vv=0;
	for(; i<l&&(!is_number(p[id][i])); i++);
	for(; i<l&&is_number(p[id][i]); i++)
		vv*=10,vv+=p[id][i]-'0';
	if(val[x].t<0)
		printf("%d 2\n",id+1);
	else
		val[x].v=vv,val[x].t++;
}

void exe(int id)
{
	int l=strlen(p[id]),kind,i,nx,j;
	memset(tmp,0,sizeof(tmp));
	for(i=0; i<l&&p[id][i]==' '; i++);
	for(j=0; i<l&&p[id][i]!=' '; i++)
		tmp[j++]=p[id][i];
	tmp[j]='\0';
//	printf("%d %s\n",id,tmp);
	for(i++; i<l&&p[id][i]==' '; i++);
	kind=get_kind(tmp);
//	printf("%d %d\n",id,kind);
	switch(kind)
	{
		case 0:
			solve0(id,i);
			exe(id+1);
			break;
		case 1:
			nx=solve1(id,i,l);
			exe(nx);
			break;
		case 2:
			solve2(id,i);
			exe(id+1);
			break;
		case 3:
			solve3(id,i);
			exe(id+1);
			break;
		case 4:
			return ;
			break;
		case 5: 
			solve5(id,i,l,tmp[0]);
			exe(id+1);
			break;
	}
}

int main()
{
	int ca,T,n;
	scanf("%d",&T);
	for(ca=1; ca<=T; ca++)
	{
		for(int i=0; i<200; i++)
			val[i].v=0,val[i].t=-1;
		printf("%d\n",ca);
		scanf("%d",&n);
		getchar();
		for(int i=0; i<n; i++)
		{
			gets(p[i]);
		}
		exe(0);
	}
	return 0;
}
