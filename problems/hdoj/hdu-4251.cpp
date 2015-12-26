#include <cstdio>
#include <algorithm>
#define N 100011
using namespace std;

int perm[N],dat[N],cnt[20][N],tree[20][N];

int cmp(int a,int b){ return a<b; }

void build(int c,int l,int r)
{
	int mid=(l+r)>>1,lc=mid-l+1,lp=l,rp=mid+1;
	if(l==r) return;
	for(int i=l; i<=mid; i++)
		if(perm[i]<perm[mid])
			lc--;
	for(int i=l; i<=r; i++)
	{
		if(i==l)
			cnt[c][i]=0;
		else
			cnt[c][i]=cnt[c][i-1];
		if(tree[c][i]==perm[mid])
		{
			if(lc>0)
			{
				lc--;
				cnt[c][i]++;
				tree[c+1][lp++]=tree[c][i];
			}
			else
				tree[c+1][rp++]=tree[c][i];
		}
		else if(tree[c][i]<perm[mid])
		{
			cnt[c][i]++;
			tree[c+1][lp++]=tree[c][i];
		}
		else
			tree[c+1][rp++]=tree[c][i];
	}
	build(c+1,l,mid);
	build(c+1,mid+1,r);
}

int query(int c,int l,int r,int ql,int qr,int k)
{
	if(l==r) return perm[l];
	int c1,c2=cnt[c][qr],mid=(l+r)>>1,d1=ql-l,d2=qr-ql+1;
	if(ql==l) c1=0;
	else c1=cnt[c][ql-1];
	c2-=c1;
	if(k<=c2)
		return query(c+1,l,mid,l+c1,l+c1+c2-1,k);
	else
		return query(c+1,mid+1,r,mid+1+d1-c1,mid+d1+d2-c1-c2,k-c2);
}

int main()
{
	int n,m,ca=1;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case %d:\n",ca++);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&dat[i]);
			tree[0][i]=perm[i]=dat[i];
		}
		sort(perm+1,perm+1+n,cmp);
		build(0,1,n);
		scanf("%d",&m);
		int x,y,k;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d",&x,&y);
			k=(y-x+2)>>1;
			printf("%d\n",query(0,1,n,x,y,k));
		}
	}
	return 0;
}
