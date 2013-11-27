#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10001
using std::sort;
typedef long long LL;

struct node{ LL x; int i; }arr[MAXN];

LL dat[MAXN];
int tag[MAXN],pos[10*MAXN];

int cmp(node a,node b){ return a.x<b.x; }
inline LL minv(LL a,LL b){ return a<b?a:b; }

int calc(int id,LL &min,LL &sum)
{
	int i,ret=1,now; LL t=dat[id];
	now=pos[t];
	tag[id]=1;
	min=t;
	sum=t;
	while(1)
	{
		t=dat[now];
		id=arr[pos[t]].i;
		if(tag[id])	break;
		now=pos[t];
		tag[id]=1;
		if(min>t)	min=t;
		sum+=t;
		ret++;
	}
	return ret;
}

int main()
{
	int n,cnt,i; LL ret,min,tmp_min,sum;
	while(scanf("%d",&n)!=EOF)
	{
		memset(tag,0,sizeof(tag));
		min=MAXN*100;
		for(i=0; i<n; i++)
		{
			scanf("%lld",&dat[i]);
			arr[i].x=dat[i];
			arr[i].i=i;
			min=minv(min,dat[i]);
		}
		sort(arr,arr+n,cmp);
		for(i=0; i<n; i++)
			pos[arr[i].x]=i;
		for(ret=i=0; i<n; i++)
			if(!tag[i])
			{
				cnt=calc(i,tmp_min,sum);
				ret+=minv(min*(cnt+1)+sum+tmp_min,sum+(cnt-2)*tmp_min);
			}
		printf("%lld\n",ret);
	}
	return 0;
}
