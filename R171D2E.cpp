#include <cstdio>
#include <cstring>

#define N 1000101

char s[N];

int main()
{
	int ret=0,l;
	scanf("%s",s);
	l=strlen(s);
	for(int i=0; s[i]; i++)
	{
		if(s[i]=='1')
		{
			if((i==0||s[i-1]=='0')&&(s[i+1]==0||s[i+1]=='0')&&(i<2||s[i-2]!='1'||s[i+2]!='1'||i+2>=l))
			{
				ret++;
				s[i]='0';
			}
		}
	}
	int tag=0;
	for(int i=0; s[i]; i++)
	{
		if(s[i]=='1')
		{
			if(tag==0)
			{
				ret+=2;
				tag=1;
			}
		}
		else
		{
			if(tag==1)
			{
				tag=0;
				if(s[i+1]=='1')
					ret--;
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}
