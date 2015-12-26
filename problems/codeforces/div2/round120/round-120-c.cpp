/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/16/2012 11:05:37 PM
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
#define N 101000
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

string s,ret;
int top,dat[N],now;

void dfs()
{
	if(now>top)
		return;
	if(dat[now]==0)
	{
		ret+="int";
		now++;
		return;
	}
	ret+="pair<";
	now++;
	dfs();
	ret+=",";
	dfs();
	ret+=">";
	return ;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0; cin>>s; i++)
		if(s=="pair")
			dat[i]=1;
		else
			dat[i]=0;
	top=i;
	now=0;
	dfs();
	if(now==top)
		cout<<ret<<endl;
	else
		puts("Error occurred");
	return 0;
}
