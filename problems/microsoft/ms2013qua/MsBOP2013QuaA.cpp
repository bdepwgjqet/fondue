#include <cstdio>
#include <sstream>
#include <iostream>
#include <map>
#define N 1001

using namespace std;

map<string,string> mp;
string s[N];

int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) 
	{
		printf("Case #%d: ",ca);
		mp.clear();
		int m,n;
		scanf("%d%d",&n,&m);
		for(int i=0; i<m; i++) 
		{ 
			string s1,s2;
			cin>>s1>>s2;
			mp[s1]=s2;
		}
		string tmp;
		getchar();
		getline(cin,tmp);
		stringstream ss(tmp);
		int top=0;
		while(ss>>s[top++]);
		top--;
		for(int i=0; i<n-1; i++) {
			for(int j=0; j<top; j++) {
				if(mp.count(s[j])>0)
					s[j]=mp[s[j]];
			}
		}
		for(int i=0; i<top; i++)
		{
			cout<<s[i];
			if(i<top-1) cout<<" ";
		}
		puts("");
	}
	return 0;
}
