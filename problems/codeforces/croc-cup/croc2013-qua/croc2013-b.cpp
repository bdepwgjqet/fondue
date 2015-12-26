#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

char s[111111];
vector<string> ret;

int main()
{
	gets(s);
	int tag=0,l=strlen(s);
	for(int i=0; i<l; i++)
	{
		if(s[i]==' ')
			continue;
		if(s[i]=='"')
		{
			string now="";
			for(i++; i<l&&s[i]!='"'; i++)
				now.push_back(s[i]);
			ret.push_back(now);
		}
		else
		{
			string now="";
			for(; s[i]!=' '&&i<l; i++)
				now.push_back(s[i]);
			ret.push_back(now);
		}
	}
	for(int i=0; i<ret.size(); i++)
	{
		cout<<"<";
		cout<<ret[i];
		cout<<">"<<endl;
	}
	return 0;
}
