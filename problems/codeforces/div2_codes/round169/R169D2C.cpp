#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 200100

using namespace std;
typedef long long LL;

int a[N],cnt[N];
struct node{ int a; }no[N<<2];
inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

int cmp(int a,int b){ return a<b; }

void down(int id)
{
	if(no[id].a)
	{
		no[L(id)].a+=no[id].a;
		no[R(id)].a+=no[id].a;
		no[id].a=0;
	}
}

void update(int id,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
	{
		no[id].a++;
		return;
	}
	int m=(l+r)>>1;
	down(id);
	if(l<=rr&&m>=ll)
		update(L(id),l,m,ll,rr);
	if(m+1<=rr&&r>=ll)
		update(R(id),m+1,r,ll,rr);
}

int query(int id,int l,int r,int p)
{
	if(l==r) return no[id].a;
	down(id);
	int m=(l+r)>>1;
	if(p<=m)
		return query(L(id),l,m,p);
	else
		return query(R(id),m+1,r,p);
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	for(int i=0; i<q; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		update(1,1,n,x,y);
	}
	for(int i=0; i<n; i++)
		cnt[i]=query(1,1,n,i+1);
	sort(cnt,cnt+n,cmp);
	sort(a,a+n,cmp);
	LL ret=0;
	for(int i=0; i<n; i++)
		ret=ret+1LL*a[i]*cnt[i];
	cout<<ret<<endl;
	return 0;
}
