#include <cstring>
#include <cstdio>
#define N 52
#define S 1000

struct node{ int next[N],fail,is; }no[S];
int top,q[S];

inline int get_ind(char x){ return x-'a'; }

void init()
{
	top=1;
	for(int i=0; i<S; i++)
	{
		no[i].is=0,no[i].fail=-1;
		for(int j=0; j<N; j++)
			no[i].next[j]=-1;
	}
}

void insert(char s[])
{
	int l=strlen(s),p=0;
	for(int i=0; i<l; i++)
	{
		int ii=get_ind(s[i]);
		if(no[p].is)
			break;
		if(no[p].next[ii]==-1)
			no[p].next[ii]=top++;
		p=no[p].next[ii];
	}
	no[p].is=1;
}

void build_ac(int n)
{
	int l,r;
	q[l=r=0]=0;
	for(; l<=r;)
	{
		int now=q[l++];
		for(int i=0; i<n; i++)
		{
			int ii=no[now].next[i];
			if(ii==-1)
			{
				if(now==0)
					no[now].next[i]=0;
				else
					no[now].next[i]=no[no[now].fail].next[i];
			}
			else
			{
				if(now==0)
					no[ii].fail=0;
				else
				{
					no[ii].fail=no[no[now].fail].next[i];
					if(no[no[ii].fail].is)
						no[ii].is=1;
				}
				q[++r]=ii;
			}
		}
	}
}
