#include <cstdio>
#include <iostream>
#include <cstring>
#define N 1001001

typedef long long LL;
using namespace std;

int le,ri,la,lb,cnt[N][10];
char sa[N],sb[N];

int getx(char s)
{
	if(s=='R') return 2;
	else if(s=='G') return 1;
	return 0;
}

int get(char a,char b)
{
	return 3*getx(a)+getx(b);
}

int main()
{
	scanf("%s%s",sa,sb);
	la=strlen(sa);
	lb=strlen(sb);
	for(int i=1; i<lb; i++)
	{
		for(int j=0; j<10; j++)
			cnt[i][j]=cnt[i-1][j];
		if(sb[i-1]!=sb[i])
			cnt[i][get(sb[i-1],sb[i])]++;
	}
	le=ri=0;
	for(; ri!=lb-1&&sa[0]!=sb[ri]; ri++);
	LL ret=ri-le+1;
	for(int i=1; i<la; i++)
	{
		if(sa[i-1]==sb[le]) le++;
		if(ri<lb-1) ri++;
		for(; ri<lb-1&&sb[ri]!=sa[i]; ) ri++;
		if(le<=ri)
			ret+=ri-le+1-(cnt[ri][get(sa[i],sa[i-1])]-cnt[le][get(sa[i],sa[i-1])]);
	}
	cout<<ret<<endl;
	return 0;
}
