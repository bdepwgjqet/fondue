#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100000

using namespace std;

char s[N],s2[N];

int main()
{
	int t;
	scanf("%d",&t);
	for(int ca=1; ca<=t; ca++)
	{
		scanf("%s%s",s,s2);
		printf("Case #%d: ",ca);
		int l1=strlen(s);
		int l2=strlen(s2);
		int ret=l2;
		for(int i=0; i<=l1-l2; i++)
		{
			int cnt=0;
			for(int j=0; j<l2&&cnt<ret; j++)
				if(s[i+j]!=s2[j])
					cnt++;
			ret=min(ret,cnt);
		}
		printf("%d\n",ret);
	}
	return 0;
}
