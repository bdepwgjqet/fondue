#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

const int N = 201111;
using namespace std;

int tag[N];

int main() {
	string s;
	while(cin>>s) {
		int pc=1;
		char pre=s[0];
		memset(tag,0,sizeof(tag));
		for(int i=1; i<s.length(); i++) {
			if(s[i]==pre) {
				pc++;
			}
			else {
				if(pc>=3) {
					for(int j=i-pc+2; j<i; j++) {
						tag[j]=1;
					}
				}
				pre=s[i];
				pc=1;
			}
		}
		if(pc>=3) {
			for(int j=s.length()-pc+2; j<s.length(); j++)
				tag[j]=1;
		}
		string ss=string("");
		for(int i=0; i<s.length(); i++) {
			if(tag[i]) continue;
			ss.push_back(s[i]);
		}
		pc=0;
		memset(tag,0,sizeof(tag));
		for(int i=0; i<ss.length()-1; ) {
			if(ss[i]==ss[i+1]) {
				pc++;
				if((pc&1)==0) {
					tag[i]=1;
				}
				i+=2;
			}
			else {
				pc=0;
				i++;
			}
		}
		for(int i=0; i<ss.length(); i++) {
			if(tag[i]) continue;
			printf("%c",ss[i]);
		}
		puts("");
	}
	return 0;
}
