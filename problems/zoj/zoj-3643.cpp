#include <cstdio>
#include <cstring>
#define N 900001

char pei[N],ori[N];
int fail[N],id[N],st[N],top,lo,lp;

void get_fail()
{
	fail[0]=-1;
	int j;
	for(int i=1; i<lp; i++)
	{
		j=fail[i-1];
		for(; j>=0&&pei[j+1]!=pei[i]; j=fail[j]);
		if(pei[j+1]==pei[i]) fail[i]=j+1;
		else fail[i]=-1;
	}
}

int solve()
{
	int ret=0,i,j;
	top=-1;
	for(i=0,j=-1; i<lo; i++)
	{
		st[++top]=i;
		for(; j>=0&&pei[j+1]!=ori[i]; j=fail[j]);
		if(pei[j+1]==ori[i])
			j=j+1;
		id[i]=j;
		if(j==lp-1)
		{
			top-=lp;
			if(top<0)
				j=-1;
			else
				j=id[st[top]];
			ret++;
		}
	}
	return ret;
}

int main()
{
	while(scanf("%s%s",pei,ori)!=EOF)
	{
		lo=strlen(ori);
		lp=strlen(pei);
		get_fail();
		printf("%d\n",solve());
	}
	return 0;
}
