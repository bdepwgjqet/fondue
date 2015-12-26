#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 500000

using namespace std;

int a[N];

int cmp(int a,int b){ return a<b; }

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	long long ret=0;
	for(int i=0; i<n; i++)
		ret+=abs(i+1-a[i]);
	cout<<ret<<endl;
	return 0;
}
