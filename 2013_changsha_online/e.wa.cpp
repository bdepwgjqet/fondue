#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;
typedef long long LL;

char day[7][20]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
map<string,int> hash;
int hour[7]={8,8,8,8,8,4,4};

int main()
{
	string fd;
	double v;
	int l;
	hash.clear();
	for(int i=0; i<7; i++) {
		hash[string(day[i])]=i;
	}
	while(cin>>fd) {
		cin>>l>>v;
		LL L=1LL*1000*l;
		cout<<l<<" "<<v<<" "<<int(1000*v)<<endl;
		LL V=1LL*int(1000*v);
		LL x=(5*8+2*4)*V;
		LL y=L/x;
		L-=y*x;
		int now=hash[fd];
		cout<<fd<<" "<<now<<" "<<hour[now]<<endl;
		cout<<L<<" "<<V<<endl;
		for(;;) {
			L-=hour[now]*V;
			if(L<=0)
				break;
			now=(now+1)%7;
		}
		cout<<day[now]<<endl;
	}
	return 0;
}
