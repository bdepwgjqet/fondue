#include <cstdio>
#include <cstring>
#include <set>
#define N 100011

using namespace std;

int a,b,c,r;
int tag[N];
int dat[N];
set<int> st;

int main()
{
	int t,n,k;
	scanf("%d",&t);
	for(int i=1; i<=t; i++)
	{
		memset(tag,0,sizeof(tag));
		st.clear();
		scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&r);
		for(int j=0; j<k+10; j++)
			st.insert(j);
		dat[0]=a;
		for(int j=1; j<k; j++)
			dat[j]=(1LL*b*dat[j-1]+c)%r;
		for(int j=0; j<k; j++)
		{
			if(dat[j]<N)
				tag[dat[j]]++;
			if(st.count(dat[j])>0)
				st.erase(dat[j]);
		}
		for(int j=k; j<4*k&&j<n; j++)
		{
			int now=*st.begin(),id=j%N,pid=((j%N-k)%N+N)%N;
			if(dat[pid]<N)
			{
				tag[dat[pid]]--;
				if(tag[dat[pid]]==0)
					st.insert(dat[pid]);
			}
			dat[id]=now;
			tag[now]++;
			if(st.count(now)>0)
				st.erase(now);
		}
		printf("Case #%d: %d\n",i,dat[]);
	}
	return 0;
}
