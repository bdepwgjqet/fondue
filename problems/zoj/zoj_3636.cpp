#include <cstdio>
#include <vector>
#define inf 0x7fffffff

using namespace std;

char s[39];
int n,k,m;
int id[32];
vector<int> vec;

inline int B(int i){ return 1<<i; }

void solve()
{
	vector<int> ans;
	for(int i=0; i<n; i++)
	{
		int nid=-1;
		for(int j=0; j<vec.size(); j++)
			if(vec[j]&B(i))
			{
				int x=vec[j];
				ans.push_back(x);
				nid=ans.size()-1;
				for(int u=0; u<vec.size(); u++)
					if(vec[u]&B(i))
						vec[u]^=x;
				break;
			}
		id[i]=nid;
	}
	vec=ans;
}

int ok(int x)
{
	int now=0;
	for(int i=0; i<n; i++)
	{
		if((x&B(i))!=(now&B(i)))
		{
			if(id[i]<0)
				return 0;
			now^=vec[id[i]];
		}
	}
	return now==x;
}

int getans(int x)
{
	int ret=inf,cnt=3;
	for(int i=0; i<=n; i++)
		for(int j=(i==n)?n:i+1; j<=n; j++)
			for(int k=(j==n)?n:j+1; k<=n; k++)
			{
				int tcnt=(i!=n)+(j!=n)+(k!=n);
				int tx=x^(1<<i)^(1<<j)^(1<<k);
				if(tx&B(n))
					tx^=B(n);
				if(ok(tx))
				{
					if(tcnt<cnt)
						cnt=tcnt,ret=tx;
					else if(tcnt==cnt)
						ret=min(ret,tx);
				}
			}
	if(ret>=inf) return -1;
	return ret;
}

void show(int x)
{
	s[n]='\0';
	for(int i=0; i<n; i++)
	{
		if(x&B(i))
			s[n-i-1]='1';
		else
			s[n-i-1]='0';
	}
	printf("%s\n",s);
}

int get()
{
	int x=0;
	for(int j=0; j<n; j++)
		x<<=1,x+=s[j]-'0';
	return x;
}

int main()
{
	while(scanf("%d%d%d",&n,&k,&m)+1)
	{
		vec.clear();
		for(int i=0; i<k; i++)
		{
			scanf("%s",s);
			int x=get();
			vec.push_back(x);
		}
		solve();
		/*
		for(int i=0; i<vec.size(); i++)
			show(vec[i]);
		puts("");
		*/
		for(int i=0; i<m; i++)
		{
			scanf("%s",s);
			int x=get();
			int y=getans(x);
			if(y<0)
				puts("NA");
			else
				show(y);
		}
	}
	return 0;
}
