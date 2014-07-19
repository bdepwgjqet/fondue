#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <cstring>
#define N 101
using namespace std;

char sa[N],sb[N],tmp[N];
int dp[N][N];
set<string> st;

void solve(int la,int lb,int len)
{
	if(len==0)
	{
		st.insert(tmp);
		return;
	}
	for(int i=1; i<=la; i++)
		for(int j=1; j<=lb; j++)
			if(dp[i][j]==len&&sa[i-1]==sb[j-1])
			{
				tmp[len-1]=sa[i-1];
				solve(i-1,j-1,len-1);
			}
}

int main()
{
	scanf("%s%s",sa,sb);
	int la=strlen(sa),lb=strlen(sb);
	memset(dp,0,sizeof(dp));
	st.clear();
	for(int i=1; i<=la; i++)
		for(int j=1; j<=lb; j++)
		{
			if(sa[i-1]==sb[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	solve(la,lb,dp[la][lb]);
	set<string>::iterator it;
	for(it=st.begin(); it!=st.end(); it++)
		cout<<*it<<endl;
	return 0;
}
