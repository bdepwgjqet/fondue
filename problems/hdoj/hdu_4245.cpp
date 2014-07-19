#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string get(string x)
{
	string ret=x;
	if(ret.length()==2)
	{
		if(ret[1]=='#')
		{
			ret[1]='b';
			if(ret[0]=='G')
				ret[0]='A';
			else
				ret[0]++;
			return ret;
		}
		else
		{
			if(ret[0]=='A')
				ret[0]='G';
			else
				ret[0]--;
			ret[1]='#';
			return ret;
		}
	}
	return ret;
}

int main()
{
	string a,b,c;
	int ca=1;
	while(cin>>a>>b)
	{
		printf("Case %d: ",ca++);
		c=get(a);
		if(c==a)
			puts("UNIQUE");
		else
		{
				cout<<c<<" "<<b<<endl;
		}
	}
	return 0;
}
