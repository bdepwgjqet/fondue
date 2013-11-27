#include <cstdio>
#include <cstring>
#define N 1001

int vis[N],q[3][N],l[3],r[3],cnt[3];

int get(char s[])
{
	int ret=(s[0]-'0')*10+s[1]-'0';
	ret*=60;
	ret+=(s[3]-'0')*10+s[4]-'0';
	return ret-480;
}

inline int getkind(int x)
{
	return (x-1)/2;
}

int main()
{
	while(scanf("%d%d%d",&cnt[0],&cnt[1],&cnt[2])!=EOF)
	{
		if(cnt[0]==0&&cnt[1]==0&&cnt[2]==0)
			break;
		memset(vis,0,sizeof(vis));
		char s[10];
		int x;
		for(; scanf("%s",s);)
		{
			if(s[0]=='#')
				break;
			scanf("%d",&x);
			vis[get(s)]=x;
		}
		for(int i=0; i<3; i++)
			r[i]=-1,l[i]=0;
		int ret=0,pre;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<3; j++)
				for(; r[j]>=l[j]&&q[j][l[j]]<=i; l[j]++);
			if(vis[i]>0)
			{
				int id=getkind(vis[i]);
				if(r[id]-l[id]+1>=cnt[id])
				{
					if(q[id][r[id]-cnt[id]+1]>i+30)
						continue;
					else
					{
						pre=q[id][r[id]-cnt[id]+1];
						q[id][++r[id]]=pre+30;
						ret+=vis[i];
					}
				}
				else
				{
					q[id][++r[id]]=i+30;
					ret+=vis[i];
				}
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
