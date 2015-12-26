#include <cstdio>
#include <vector>
#define N 100011

using namespace std;

int st1[N],st2[N];

vector<int> ans;
vector<int> cnt;

int main()
{
	int m,n;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&m)+1)
	{
		ans.clear();
		cnt.clear();
		for(int i=0; i<m; i++)
			scanf("%d",&st1[i]);
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			scanf("%d",&st2[i]);
		int n1=m-1,n2=n-1,now=0,first=1;
		for(; n1>=0||n2>=0; )
		{
			int c=0;
			for(; n1>=0&&st1[n1]==now; n1--,c++)
				ans.push_back(n1+1);
			for(; n2>=0&&st2[n2]==now; n2--,c++)
				ans.push_back(n2+1+m);
			now^=1;
			if(c>0)
			{
				if(first==0)
					cnt.push_back(c);
			}
			first=0;
		}
		for(int i=ans.size()-1; i>=0; i--)
			printf("%d ",ans[i]);
		puts("");
		printf("%d\n",cnt.size());
		int cc=0;
		for(int i=cnt.size()-1; i>=0; i--)
		{
			cc+=cnt[i];
			printf("%d ",cc);
		}
		puts("");
	}
	return 0;
}
