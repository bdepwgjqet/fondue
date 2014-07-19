#include <cstdio>
#include <map>

using namespace std;

map<int,int> mp;
map<int,int>::iterator it;

int f(int x){ return x*x*x; }

int main()
{
	for(int i=1; i<100; i++)
		for(int j=1; j<100; j++) 
			for(int k=1; k<100; k++)
				mp[f(i+j+k)-f(i)-f(j)-f(k)]++;
	int i=1;
	for(it=mp.begin(); it!=mp.end(); it++)
	{
		printf("%d %d\n",it->first/3,it->second);
		i++;
		if(i>=110) break;
	}
	return 0;
}
