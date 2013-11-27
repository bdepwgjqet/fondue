#include <cstdio>
#include <algorithm>

using namespace std;

char s[1001];

int main()
{
	int n,t;
	while(scanf("%d%d%s",&n,&t,s)+1)
	{
		for(int i=0; i<t; i++)
			for(int j=1; j<n; j++)
				if(s[j]=='G'&&s[j-1]=='B')
				{
					swap(s[j],s[j-1]);
					j++;
				}
		printf("%s\n",s);
	}
	return 0;
}
