/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/26/2012 01:19:19 PM
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
#define N 1010000
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

set<int> st;
set<int>::iterator it;
struct node{ int x,i; }no[N];
int cmp(node a,node b){ return a.x<b.x; }
int ret[N],dat[N];

int main()
{
	int t,n;
	scanf("%d",&t);
	for(int ca=1; ca<=t; ca++)
	{
		st.clear();
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&no[i].x);
			no[i].i=i;
			dat[i]=no[i].x;
		}
		sort(no,no+n,cmp);
		int tmp,dis;
		int j;
		for(int i=0; i<n; i=j)
		{
			/*
			for(it=st.begin(); it!=st.end(); it++)
				printf("%d ",*it);
			puts("");
			*/

			for(j=i+1; j<n; j++) 
				if(no[j].x!=no[i].x)
					break;
			for(int k=i; k<j; k++)
			{
				st.insert(no[k].i);
				it=st.find(no[k].i);
				tmp=-1;
				dis=inf;
				if(it!=st.begin())
				{
					it--;
					if(dis>no[k].i-(*it))
					{
						dis=no[k].i-(*it);
						tmp=*it;
					}
					it++;
				}
				it++;
				if(it!=st.end())
				{
					if(dis>(*it)-no[k].i)
					{
						dis=(*it)-no[k].i;
						tmp=*it;
					}
				}
				st.erase(no[k].i);
				if(tmp==-1)
					ret[no[k].i]=0;
				else
					ret[no[k].i]=dat[tmp];
			}
			for(int k=i; k<j; k++)
				st.insert(no[k].i);
		}
		printf("%d",ret[0]);
		for(int i=1; i<n; i++)
			printf(" %d",ret[i]);
		puts("");
	}
	return 0;
}
