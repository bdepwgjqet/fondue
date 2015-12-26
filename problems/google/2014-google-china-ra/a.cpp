#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char ans[20][20]={"","","double", "triple", "quadruple", "quintuple",
"sextuple", "septuple", "octuple", "nonuple",  "decuple"};
char num[20][20]={"zero","one","two","three","four","five","six","seven","eight","nine"};
vector<int> vec;

void go(char s[],int l,int r) {
	int c=0,pre=-1;
	for(int i=l; i<r; i++) {
		if(s[i]-'0'==pre) {
			c++;
			continue;
		}
		else {
			if(c>=1&&pre>=0) {
				if(c==1) {
					printf(" %s",num[pre]);
				}
				else if(c==11) {
					for(int j=0; j<c; j++) {
						printf(" %s",num[pre]);
					}
				}
				else {
					printf(" %s %s",ans[c],num[pre]);
				}
			}
			c=1;
			pre=s[i]-'0';
		}
	}
	if(pre>=0&&c>=1) {
		if(c==1) {
			printf(" %s",num[pre]);
		}
		else if(c==11) {
			for(int j=0; j<c; j++) {
				printf(" %s",num[pre]);
			}
		}
		else {
			printf(" %s %s",ans[c],num[pre]);
		}
	}
}

int main() {
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++) {
		printf("Case #%d:",ca);
		char s[6000],div[6000];
		scanf("%s%s",s,div);
		vec.clear();
		int x=0;
		for(int i=0; i<strlen(div); i++) {
			if(div[i]=='-') {
				vec.push_back(x);
				x=0;
				continue;
			}
			x*=10;
			x+=div[i]-'0';
		}
		vec.push_back(x);
		int l=0,r;
		for(int i=0; i<vec.size(); i++) {
			r=l+vec[i];
			go(s,l,r);
			l=r;
		}
		puts("");
	}
	return 0;
}
