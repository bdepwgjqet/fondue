#include <cstdio>
#include <algorithm>
using namespace std;

int d[9];

int main()
{
	int ca=1;
	while(scanf("%d",&d[0])!=EOF)
	{
		printf("Case %d: ",ca++);
		for(int i=1; i<4; i++)
			scanf("%d",&d[i]);
		sort(d,d+4);
		printf("%d\n",d[3]+d[2]);
	}
	return 0;
}
