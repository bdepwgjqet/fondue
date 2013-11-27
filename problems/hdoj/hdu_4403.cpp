#include <cstdio>
#include <cstring>

char s[100];

inline int B(int i){ return 1<<i; }
typedef long long LL;

int solve()
{
	int i,l=strlen(s);
	int ret=0;
	ret=0;
	for(i=0; i<l-1; i++)
	{
		for(int j=0; j<B(l-1); j++)
		{
			if(B(i)&j)
			{
				LL ll=0,rr=0,now=s[0]-'0';
				for(int k=0; k<i; k++)
				{
					if(B(k)&j)
						ll+=now,now=s[k+1]-'0';
					else
						now*=10,now+=s[k+1]-'0';
				}
				ll+=now;
				now=s[i+1]-'0';
				for(int k=i+1; k<l-1; k++)
				{
					if(B(k)&j)
						rr+=now,now=s[k+1]-'0';
					else
						now*=10,now+=s[k+1]-'0';
				}
				rr+=now;
				if(ll==rr)
					ret++;
			}
		}
	}
	return ret;
}

int main()
{
	while(scanf("%s",s)!=EOF)
	{
		if(strcmp(s,"END")==0)
			break;
		solve();
		printf("%d\n",solve());
	}
	return 0;
}
