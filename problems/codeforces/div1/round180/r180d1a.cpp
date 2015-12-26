#include <cstdio>
#include <cstring>
#define N 1101

char a[N],b[N];
int la,lb;

int ok(int l)
{
	for(int i=0; i<l; i++)
		if(b[i]!=a[la-l+i])
			return 0;
	return 1;
}

int gao(int l)
{
	int ia=0,ib=l,ra=la-l,cnt=0;
	for(int i=0; i<la; i++)
		cnt+=a[i]-'0';
	for(; ia<=ra&&ib<lb; ib++)
	{
		int tag=0;
		if(b[ib]=='0')
		{
			if(cnt&1)
			{
				if(ia==ra) return 0;
				for(; ia<ra; ia++)
				{
					if(a[ia]=='1')
					{
						ia++;
						cnt^=1;
						tag=1;
						break;
					}
				}
				if(tag==0) return 0;
			}
		}
		else
		{
			if(cnt&1)
				cnt^=1;
			else
			{
				if(ia==ra) return 0;
				for(; ia<ra; ia++)
					if(a[ia]=='1')
					{
						ia++;
						tag=1;
						break;
					}
				if(tag==0) return 0;
			}
		}
	}
	return ib>=lb;
}

int main()
{
	scanf("%s%s",a,b);
	la=strlen(a);
	lb=strlen(b);
	for(int i=0; i<=la&&i<=lb; i++) {
		if(ok(i))
		{
			if(gao(i))
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}
