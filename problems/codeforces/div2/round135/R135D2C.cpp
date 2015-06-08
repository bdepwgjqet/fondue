/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/28/2012 12:04:59 AM
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
#define N 500010
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

char s[N],rs[N],rsa[N],rsb[N];

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		scanf("%s",&s);
		if(k==2)
		{
			int reta=0,retb=0;
			for(int i=0; i<n; i++)
			{
				rsa[i]=(i&1)+'A';
				if(rsa[i]!=s[i])
					reta++;
			}
			for(int i=0; i<n; i++)
			{
				rsb[i]=((i&1)+1)%2+'A';
				if(rsb[i]!=s[i])
					retb++;
			}
			rsa[n]=rsb[n]='\0';
			if(reta<retb)
				printf("%d\n%s\n",reta,rsa);
			else
				printf("%d\n%s\n",retb,rsb);
		}
		else
		{
			int pre=s[0]-'A',ret=0;
			rs[0]=s[0];
			for(int i=1; i<n; i++)
			{
				if(s[i]==pre+'A')
				{
					if(i==n-1)
					{
						pre=(pre+1)%k;
						rs[i]=pre+'A';
					}
					else
					{
						pre=(pre+1)%k;
						if(pre==s[i+1]-'A')
							pre=(pre+1)%k;
						rs[i]=pre+'A';
					}
					ret++;
				}
				else
				{
					pre=s[i]-'A';
					rs[i]=s[i];
				}
			}
			rs[n]='\0';
			printf("%d\n%s\n",ret,rs);
		}
	}
	return 0;
}
