#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define N 101
typedef long long LL;
using namespace std;

char s1[N],s2[N],s3[N],s[N];
LL dp[N][2];
int dat[3][N];

void getse(int x,int &st1,int &ed1)
{
	if(x==-1)
		st1=0,ed1=10;
	else if(x==-2)
		st1=1,ed1=10;
	else
		st1=x,ed1=x+1;
}

int main()
{
	int l,l1,l2,l3,ca=1;
	while(scanf("%s",s)!=EOF)
	{
		memset(dat,0,sizeof(dat));
		memset(dp,0,sizeof(dp));
		int ll=strlen(s),i;
		for(i=0; i<ll; i++)
		{
			if(s[i]=='+')
				break;
			s1[i]=s[i];
		}
		l1=i;
		s1[i++]='\0';
		for(; i<ll; i++)
		{
			if(s[i]=='=')
				break;
			s2[i-l1-1]=s[i];
		}
		l2=i-l1-1;
		s2[l2]='\0';
		i++;
		for(; i<ll; i++)
			s3[i-l1-l2-2]=s[i];
		l3=ll-l1-l2-2;
		s3[l3]='\0';
		printf("Case %d: ",ca++);
		for(int i=0; i<l1; i++)
			dat[0][l1-i-1]=(s1[i]=='?')?-1:s1[i]-'0';
		for(int i=0; i<l2; i++)
			dat[1][l2-i-1]=(s2[i]=='?')?-1:s2[i]-'0';
		for(int i=0; i<l3; i++)
			dat[2][l3-i-1]=(s3[i]=='?')?-1:s3[i]-'0';
		l=max(l1,max(l2,l3));
		if(s1[0]=='?'&&l1>1)
			dat[0][l1-1]=-2;
		if(s2[0]=='?'&&l2>1)
			dat[1][l2-1]=-2;
		if(s3[0]=='?'&&l3>1)
			dat[2][l3-1]=-2;
		dp[0][0]=1;
		int st1,ed1,st2,ed2,st3,ed3;
		for(int i=1; i<=l; i++)
		{
			getse(dat[0][i-1],st1,ed1);
			for(int u=st1; u<ed1; u++)
			{
				getse(dat[1][i-1],st2,ed2);
				for(int v=st2; v<ed2; v++)
				{
					getse(dat[2][i-1],st3,ed3);
					for(int t=st3; t<ed3; t++)
					{
						if(u+v-t==-1)
							dp[i][0]+=dp[i-1][1];
						if(u+v-t==9)
							dp[i][1]+=dp[i-1][1];
						if(u+v-t==0)
							dp[i][0]+=dp[i-1][0];
						if(u+v-t==10)
							dp[i][1]+=dp[i-1][0];
					}
				}
			}
		}
		cout<<dp[l][0]<<endl;
	}
	return 0;
}
