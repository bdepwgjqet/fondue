#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#define N 10011

using namespace std;

string s[5][9]={"I","II","III","IV","V","VI","VII","VIII","IX",
"X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
"C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
"M","MM","MMM"}; 

struct node{ string s; int x; }no[N];

int cmp(node a,node b){ return a.s<b.s; }

void dfs(int x,int i,int l)
{
	if(x==0)
		return;
	dfs(x/10,i,l+1);
	int now=x%10;
	if(now==0)
		return;
	no[i].s+=s[l][now-1];
}

void get(int i)
{
	int x=no[i].x;
	dfs(x,i,0);
}

int main()
{
	int n,ts;
	scanf("%d",&ts);
	while(scanf("%d",&n),ts--)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d",&no[i].x);
			no[i].s="";
			get(i);
		}
		sort(no,no+n,cmp);
		/*
		for(int i=0; i<n; i++)
			cout<<no[i].s<<" ";
		puts("");
		*/
		printf("%d",no[0].x);
		for(int i=1; i<n; i++)
			printf(" %d",no[i].x);
		puts("");
	}
	return 0;
}
