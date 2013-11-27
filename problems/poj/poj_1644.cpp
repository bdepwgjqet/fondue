#include <cstdio>
#include <cstring>
#define inf 0x3fffffff
#define N 1001
#define X 500
typedef long long LL;

double ret[55][N];
int ins[N];
char s[N];

int get()
{
	int l=strlen(s),ret=0,tag;
	if(s[0]=='0')
		return 0;
	if(s[0]=='+')
		tag=1;
	else
		tag=-1;
	for(int i=1; i<l; i++)
		ret*=10,ret+=s[i]-'0';
	return ret*tag;
}

int main()
{
	int t,m,n;
	scanf("%d",&t);
	for(; t--;)
	{
		scanf("%d%d",&m,&n);
		memset(ins,0,sizeof(ins));
		memset(ret,0,sizeof(ret));
		for(int i=X+1; i<=X+m; i++)
		{
			scanf("%s",s);
			if(s[0]=='L')
				ins[i]=inf;
			else
			{
				ins[i]=get();
			}
		}
		ret[0][X]=1;
		for(int i=1; i<=n; i++)
		{
			for(int j=0; j<X+m; j++)
			{
				if(ret[i-1][j]>0)
				{
					if(ins[j+1]==inf)
						ret[i+1][j+1]+=2*ret[i-1][j];
					else
						ret[i][j+1+ins[j+1]]+=ret[i-1][j];
					if(ins[j+2]==inf)
						ret[i+1][j+2]+=2*ret[i-1][j];
					else
						ret[i][j+2+ins[j+2]]+=ret[i-1][j];
				}
			}
			for(int j=X+m; j<N; j++)
				if(ret[i-1][j]>0)
					ret[i][X+m+1]+=2*ret[i-1][j];
		}
		double r=0;
		r=ret[n][X+m+1]/(1LL<<n);
		if(r==0.5)
			printf("Push. %.4f\n",r);
		else if(r<0.5)
			printf("Bet against. %.4f\n",r);
		else
			printf("Bet for. %.4f\n",r);
	}
	return 0;
}
