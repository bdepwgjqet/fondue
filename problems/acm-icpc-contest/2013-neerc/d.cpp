#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char ini[1010];

string ret;
string s;
string xiao,zong,hua;

char upper(char x) {
	if('A'<=x && 'Z'>=x)
		return x;
	return x-'a'+'A';
}

char small(char x) {
	if('a'<=x && 'z'>=x)
		return x;
	return x-'A'+'a';
}

int is(char x) {
	return ('a'<=x && 'z'>=x) || ('A'<=x && 'Z'>=x);
}

int main() {
	while(gets(ini)!=NULL) {
		int l=strlen(ini);
		s=string(ini);
		ret=string("");
		for(int i=0; i<l; ) {
			if(s[i]=='(') {
				int j=i+1;
				for(; j<l; j++)
					if(s[j]==')')
						break;
				xiao=s.substr(i+1,j-i-1);
				i=j+1;
			}
			else if(s[i]=='[') {
				int j=i+1;
				for(; j<l; j++)
					if(s[j]==']')
						break;
				zong=s.substr(i+1,j-i-1);
				i=j+1;
			}
			else if(s[i]=='{') {
				int j=i+1;
				for(; j<l; j++)
					if(s[j]=='}')
						break;
				hua=s.substr(i+1,j-i-1);
				i=j+1;
			}
			else if(s[i]==',') {
				int ful=0;
				if(hua.length()>0)
					ret=ret+string(" ")+hua;
				if(xiao.length()>0)
					ret=ret+string(" ")+xiao;
				if(zong.length()>0)
					ret=ret+string(" ")+zong;
				ret=ret+string(",");
				int j=i+1;
				for(; j<l; j++)
					if(s[j]=='('||s[j]=='['||s[j]=='{')
						break;
				ret+=s.substr(i+1,j-i-2);
				i=j;
			}
			else
				i++;
		}
		int ful=0;
		if(hua.length()>0)
			ret=ret+string(" ")+hua;
		if(xiao.length()>0)
			ret=ret+string(" ")+xiao;
		if(zong.length()>0)
			ret=ret+string(" ")+zong;
		string ans=ret.substr(1,ret.length()-1);
		ans[0]=upper(ans[0]);
		for(int i=1; i<ans.length(); i++) {
			if(is(ans[i]))
				ans[i]=small(ans[i]);
		}
		cout<<ans<<endl;
	}
	return 0;

}
