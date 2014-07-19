//bugs
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




//new
//AC automation
//hdu 4787 2013_chengdu_regional_g_gre_words_revenge
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;

const int X = 2;
const int N = 1000010;

int q[N];

struct node {
	int next[X],fail,is;
	LL cnt;
	void init() {
		fail=-1;
		is=0;
		cnt=0;
		for(int i=0; i<X; i++)
			next[i]=-1;
	}
};

struct AC {
	node no[N];
	int top;

	void init() {
		top=1;
		no[0].init();
	}

	int next_node() {
		no[top].init();
		return top++;
	}

	int gid(char x) {
		return x-'0';
	}

	void insert(string s) {
		int p=0;
		for(int i=0; i<s.length(); i++) {
			int ii=gid(s[i]);
			if(no[p].next[ii]==-1) {
				no[top].init();
				no[p].next[ii]=top++;
			}
			p=no[p].next[ii];
		}
		no[p].is=1;
	}

	void build_ac() {
		int l=0,r=0;
		q[0]=0;
		for(; l<=r;) {
			int now=q[l++];
			for(int i=0; i<X; i++) {
				int ni=no[now].next[i];
				if(ni!=-1) {
					no[ni].cnt=no[ni].is;
					if(now==0) {
						no[ni].fail=0;
					} else {
						int pre=no[now].fail;
						for(; pre!=-1&&no[pre].next[i]==-1;)
							pre=no[pre].fail;
						if(pre==-1) {
							no[ni].fail=0;
						}
						else {
							no[ni].fail=no[pre].next[i];
							no[ni].cnt+=no[no[ni].fail].cnt;
						}
					}
					q[++r]=ni;
				} 
			}
		}
	}

	LL query(string s) {
		int p=0;
		LL ret=0;
		for(int i=0; i<s.length(); i++) {
			int ii=gid(s[i]);
			for(; p!=0 && no[p].next[ii]==-1;)
				p=no[p].fail;
			p=no[p].next[ii];
			if(p==-1)
				p=0;
			ret+=no[p].cnt;
		}
		return ret;
	}

	int find(string s) {
		int p=0;
		for(int i=0; i<s.length(); i++) {
			int ii=gid(s[i]);
			p=no[p].next[ii];
			if(p==-1)
				return 0;
		}
		if(no[p].is) return 1;
		return 0;
	}
}hp,buf;

char ts[5*N];

void dfs(int p1,int p2) {
	for(int i=0; i<2; i++) {
		if(buf.no[p1].next[i]!=-1) {
			if(hp.no[p2].next[i]==-1) {
				hp.no[p2].next[i]=hp.next_node();
			}
			int n2=hp.no[p2].next[i];
			int n1=buf.no[p1].next[i];
			hp.no[n2].is|=buf.no[n1].is;
			dfs(n1,n2);
		}
	}
}

//merge two AC
void merge() {
	dfs(0,0);
	buf.init();
	hp.build_ac();
}
