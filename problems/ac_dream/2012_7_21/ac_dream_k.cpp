/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/21/2012 07:33:49 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

string s[N],ss;
int bs[N],fs[N],bt,ft,top,now;

int main()
{
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case %d:\n",ca++);
		bt=ft=-1;
		top=1;
		now=0;
		s[0]=string("http://www.lightoj.com/");
		while(cin>>ss)
		{
			if(ss=="QUIT")
				break;
			if(ss=="VISIT")
			{
				bs[++bt]=now;
				cin>>s[top++];
				now=top-1;
				cout<<s[top-1]<<endl;
				ft=-1;
			}
			else if(ss=="BACK")
			{
				if(bt<0)
					puts("Ignored");
				else
				{
					fs[++ft]=now;
					cout<<s[bs[bt]]<<endl;
					now=bs[bt];
					bt--;
				}
			}
			else
			{
				if(ft<0)
					puts("Ignored");
				else
				{
					bs[++bt]=now;
					cout<<s[fs[ft]]<<endl;
					now=fs[ft];
					ft--;
				}
			}
		}
	}
	return 0;
}
