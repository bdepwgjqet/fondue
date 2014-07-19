#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#define N 530000 

using namespace std;

struct node{ int l; double v;
	friend int operator < (node a,node b){ return a.l<b.l; }
};
double dp[N];
vector<node> vec[N];
string mname[13]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
int day[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
map<string,int> mp;


char s[20];

int get()
{
	int ret=0,x,y;
	scanf("%s",s);
	ret=day[mp[string(s)]]*24*60;
	scanf("%d%s",&x,s);
	ret+=(x-1)*24*60;
	scanf("%d:%d%s",&x,&y,s);
	ret+=x*60+y;
	if(s[0]=='p')
		ret+=12*60;
	return ret;
}

vector<node>::iterator it;

int main()
{
	int n;
	for(int i=0; i<12; i++)
		mp[mname[i]]=i;
	for(int i=1; i<=12; i++)
		day[i]+=day[i-1];
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0; i<N; i++)
			vec[i].clear();
		for(int i=0; i<n; i++)
		{
			double v;
			int x=get(),y=get();
			scanf("%lf",&v);
			node tmp;
			tmp.l=x,tmp.v=v;
			vec[y].push_back(tmp);
		}
		for(int i=1; i<N; i++)
		{
			dp[i]=dp[i-1];
			for(int j=0; j<vec[i].size(); j++)
			{
				dp[i]=max(dp[i],dp[max(vec[i][j].l-5,0)]+vec[i][j].v);
			}
		}
		printf("%.1lf\n",dp[N-1]);
	}
	return 0;
}
