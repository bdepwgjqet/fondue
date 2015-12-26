#include <cstdio>
#include <cstring>
#include <algorithm>

const int inf=0x7ffff;
using namespace std;

int pos_to_id[2][12];
int vis[2][1<<12];
int n;

int bin(int i) { return 1<<i; }

int go(int kind,int pos,int now) 
{
	int flag[2][12];
	for(int i=0; i<2; i++)
		for(int j=0; j<12; j++)
			if(now&bin(12*i+j)) flag[i][j]=1;
			else flag[i][j]=0;
	int ret=0;
	if(kind==0) 
	{
		if(pos-3>=0) 
			if(flag[0][pos-3]&&flag[1][pos-4+pos/3]&&flag[1][pos-4+pos/3+1]) 
				ret++;
		if(pos+3<=11) 
			if(flag[0][pos+3]&&flag[1][pos+pos/3]&&flag[1][pos+pos/3+1]) 
				ret++;
	}
	else
	{
		if(pos-1>=(pos/4)*4) 
			if(flag[1][pos-1]&&flag[0][pos-1-pos/4]&&flag[0][pos-1-pos/4+3]) 
				ret++;
		if(pos+1<=(pos/4)*4+3) 
			if(flag[1][pos+1]&&flag[0][pos-pos/4]&&flag[0][pos-pos/4+3]) 
				ret++;
	}
	return ret;
}

int dp(int kind,int now,int initial) 
{
	if(vis[kind][now]<inf)
		return vis[kind][now];
	if(now==bin(24-n)-1)
		return vis[kind][now]=0;
	int ret=inf;
	for(int k=0; k<2; k++) 
	{
		for(int i=0; i<12; i++)
		{
			if((initial&bin(k*12+i))==0) 
			{
				int flag=(kind==1?-1:1);
				int pre_v=flag*go(k,i,initial|bin(k*12+i));
				int next_v=dp((kind+1)%2,now|bin(pos_to_id[k][i]),initial|bin(k*12+i))+pre_v;
				if(ret==inf)
					ret=next_v;
				else 
				{
					if(kind==0)
						ret=max(ret,next_v);
					else
						ret=min(ret,next_v);
				}
			}
		}
	}
	return vis[kind][now]=ret;
}

void solve()
{
	int initial=0;
	int pre_v[2]={0,0};
	scanf("%d",&n);
	for(int i=0; i<n; i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		if(abs(y-x)==1) 
		{
			pre_v[i%2]+=go(0,min(x,y)-min(x,y)/4,initial);
			initial|=bin(min(x,y)-min(x,y)/4);
		}
		else 
		{
			pre_v[i%2]+=go(1,min(x,y),initial);
			initial|=bin(12+min(x,y));
		}
	}
	int c=0;
	memset(pos_to_id,-1,sizeof(pos_to_id));
	for(int i=0; i<2; i++)
		for(int j=0; j<12; j++) 
			if((initial&bin(i*12+j))==0) 
				pos_to_id[i][j]=c++;
	for(int i=0; i<2; i++)
		for(int j=0; j<bin(12); j++)
			vis[i][j]=inf;
	if(dp(n%2,0,initial)+pre_v[0]-pre_v[1]>0) 
		puts("Tom200");
	else 
		puts("Jerry404");
}


int main() 
{
	int ttl_case;
	scanf("%d",&ttl_case);
	for(int __=1; __<=ttl_case; __++) 
	{
		printf("Case #%d: ",__);
		solve();
	}
}
