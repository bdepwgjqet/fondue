#include <cstdio>
#include <iostream>
#include <string>
#define N 1001

using namespace std;

string s;
int st1[N],st2[N],t1,t2;

void show(char x,int tag)
{
	if(x>='a')
		x-='a';
	else
		x-='A';
	printf("%c",(x+'A')+(1-tag)*('a'-'A'));
}

int main()
{
	while(cin>>s)
	{
		size_t it;
		while((it=s.find("<UP>"))!=string::npos)
			s.replace(it,4,"1");
		while((it=s.find("</UP>"))!=string::npos)
			s.replace(it,5,"2");
		while((it=s.find("<DOWN>"))!=string::npos)
			s.replace(it,6,"3");
		while((it=s.find("</DOWN>"))!=string::npos)
			s.replace(it,7,"4");
		t1=-1,t2=-1;
		for(int i=0; i<s.length(); i++)
		{
			if(s[i]=='1')
				st1[++t1]=i;
			else if(s[i]=='2')
				--t1;
			else if(s[i]=='3')
				st2[++t2]=i;
			else if(s[i]=='4')
				--t2;
			else
			{
				if(t1<0&&t2<0)
					printf("%c",s[i]);
				else if(t1>=0&&t2>=0)
					show(s[i],st1[t1]>st2[t2]);
				else if(t1>=0)
					show(s[i],1);
				else
					show(s[i],0);
			}
		}
		puts("");
	}
	return 0;
}
