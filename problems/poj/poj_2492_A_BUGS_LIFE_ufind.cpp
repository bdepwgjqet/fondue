#include <cstdio>
#include <cstring>
#define MAXN 100011

inline int sig(int x){ return x>0?1:-1; }
inline int abs(int x){ return x>0?x:-x; }

struct ufind
{
	int p[MAXN],t;

	void init(){ memset(p,0,sizeof(p)); }

	void _run(int &x)
	{
		for( ; p[t=abs(x)]; x=sig(x)*p[abs(x)],p[t]=sig(p[t])*(p[abs(x)]?p[abs(x)]:abs(p[t])));
	}

	void _run_both(int &i,int &j)
	{
		_run(i); _run(j);
	}

	void _set_side(int x,int i,int j)
	{
		p[abs(i)]=sig(i)*(abs(i)==abs(j)?0:(x*j));

	}

	int _judge_side(int x,int i,int j)
	{
		return ((i==x*j)&&i);
	}

	int set_friend(int i,int j)
	{
		_run_both(i,j);
		_set_side(1,i,j);
		return !_judge_side(-1,i,j);
	}

	int set_enemy(int i,int j)
	{
		_run_both(i,j);
		_set_side(-1,i,j);
		return !_judge_side(1,i,j);
	}

	int is_friend(int i,int j)
	{
		_run_both(i,j);
		return _judge_side(1,i,j);
	}

	int is_enemy(int i,int j)
	{
		_run_both(i,j);
		return _judge_side(-1,i,j);
	}
}uf;

int main()
{
	int t,ca,n,m,i,x,y,tag;
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		printf("Scenario #%d:\n",ca);
		scanf("%d%d",&n,&m);
		uf.init();
		for(tag=i=0; i<m; i++)
		{
			scanf("%d%d",&x,&y);
			if(tag)	continue;
			if(uf.is_friend(x,y))
				tag=1;
			else
				uf.set_enemy(x,y);
		}
		if(tag)
			puts("Suspicious bugs found!");
		else
			puts("No suspicious bugs found!");
		puts("");
	}
	return 0;
}
