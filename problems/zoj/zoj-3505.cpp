#include <cstdio> 
#include <vector>
#include <cstring>

using namespace std;
typedef long long LL;

char s[24];
LL dp[24],three[24];
vector<int> vec;

void init()
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	three[0]=1;
	for(int i=1; i<24; i++)
		three[i]=three[i-1]*3;
	for(int i=1; i<24; i++)
		dp[i]=three[i]+dp[i-1];
}

LL get(int n)
{
	int l=strlen(s);
	LL ret=0;
	int pre=0;
	for(int i=0; i<l; i++)
	{
		LL x;
		int c=0;
		for(int j=0; j<s[i]-'0'; j++)
		{
			if(j==pre)
				continue;
			c++;
		}
		x=c*dp[n-i-1];
		pre=s[i]-'0';
		ret+=x+1;
	}
	return ret;
}

int arr[10];

void show(int n,LL x)
{
	vec.clear();
	int pre=0;
	for(int i=0; i<n&&x>0; i++)
	{
		int c=0;
		for(int j=0; j<4; j++)
		{
			if(j==pre)
				continue;
			arr[c++]=j;
		}
		int now=x/dp[n-i-1],mod=x%dp[n-i-1];
//		printf("%d %lld %lld\n",now,x,dp[n-i-1]);
		if(mod==0)
			now--,mod=dp[n-i-1];
		vec.push_back(arr[now]);
		pre=arr[now];
		x=mod-1;
	}
	for(int i=0; i<vec.size(); i++)
		printf("%c",vec[i]+'0');
	puts("");
}

int main()
{
	int n;
	LL k;
	init();
	while(scanf("%d%lld",&n,&k)+1)
	{
		scanf("%s",s);
		LL id=get(n);
		id-=k;
		show(n,id);
	}
	return 0;
}
