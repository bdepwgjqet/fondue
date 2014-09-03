#include <cstdio>
#include <algorithm>
#include <set>
#define M 1000000000
#define N 100101

using namespace std;
typedef long long LL;

LL dat[N];
set<LL> st;

int cmp(int a,int b){ return a<b; }

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)+1)
	{
		st.clear();
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d",&x);
			st.insert(1LL*x);
			dat[i]=1LL*x;
		}
		sort(dat,dat+n,cmp);
		int ret=0;
		for(int i=0; i<n; i++)
		{
			LL x=dat[i];
			int cnt=0;
			if(st.count(dat[i])>0)
			{
				for(;;)
				{
					if(st.count(x)==0)
						break;
					cnt++;
					st.erase(x);
					x=x*k;
					if(x>M)
						break;
				}
			}
			ret+=cnt/2+(cnt&1);
		}
		printf("%d\n",ret);
	}
	return 0;
}
