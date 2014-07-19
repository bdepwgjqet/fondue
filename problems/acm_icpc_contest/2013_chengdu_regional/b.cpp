#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d:\n",ca);
		char c;
		for(;;) {
			if(c=='<')
				break;
			c=getchar();
			if(c==' ' || c=='\n' || c=='\t') { 
				continue;
			}
			break;
		}
		int cnt=0;
		for(;;) {
			string s=string("");
			if(c=='<') {
				s.push_back(c);
				for(;;) {
					c=getchar();
					if(c=='\n') {
						s.push_back(' ');
						continue;
					}
					s.push_back(c);
					if(c=='>') {
						break;
					}
				}
				for(;;) {
					c=getchar();
					if(c==' ' || c=='\n' || c=='\t') { 
						continue;
					}
					break;
				}
			} else {
				s.push_back(c);
				for(;;) {
					c=getchar();
					if(c=='\n' || c==' ' || c=='\t') {
						if(s[s.length()-1]!=' ')
							s.push_back(' ');
						continue;
					}
					if(c=='<')
						break;
					s.push_back(c);
				}
			}
			for(int j=0; j<cnt-1; j++)
				printf(" ");
			if((!(s[0]=='<'&&s[1]=='/'))&&cnt>0)
				printf(" ");
			for(;;) {
				if(s[s.length()-1]==' ' || s[s.length()-1]=='\t'|| s[s.length()-1]=='\n')
					s.erase(s.end()-1);
				else
					break;
			}
			cout<<s<<endl;
			if(s==string("</html>")) {
				break;
			}
			if(s[0]=='<') {
				if(s[1]=='/')
					cnt--;
				else if(s[s.length()-2]=='/')
					;
				else
					cnt++;
			} 
		}
	}
	return 0;
}
