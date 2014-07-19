#include <cstdio>
#include <map>
#include <string>
using namespace std;

char ret[21][100]={"","I","II" ,"III" ,"IV", "V", "VI" ,"VII", "VIII","IX","X","XI","XII"};

map<string,int> mp;
char s[100];

int main()
{
	int n,ca=1;
	for(int i=1; i<=12; i++)
		mp[string(ret[i])]=i;
	while(scanf("%s",&s)!=EOF)
	{
		printf("Case %d: ",ca++); 
		printf("%d\n",mp[string(s)]);
	}
	return 0;
}
