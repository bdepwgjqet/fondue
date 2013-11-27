#include <cstdio>
#include <cstring>
#define MAXN 100011

//1st_kind
struct ufind
{
	int p[MAXN],t;
	void ini(){ memset(p,0,sizeof(p)); }
	void run(int &x)
	{
		int y=x;
		for(; p[t=x]; x=p[x],p[t]=(p[x]?p[x]:x));
		for(; p[t=y]; p[y]=x,y=p[t]);
	}
	int isfriend(int i,int j){ run(i); run(j); return i==j&&i; }
	void setfriend(int i,int j){ run(i); run(j); p[i]=(i==j)?0:j; }
}uf;

//2nd_kind
struct ufind
{
	int p[N],t;
	void init()
	{ 
		for(int i=0; i<=N; i++)
			p[i]=i;
	}
	void run(int &x)
	{
		int y=x;
		for(; p[t=x]!=x; x=p[x],p[t]=p[x]);
		for(; p[t=y]!=x; p[y]=x,y=p[t]);
	}
	int isfriend(int i,int j)
	{
		run(i); run(j);
		return i==j;
	}
	void setfriend(int i,int j)
	{
		run(i); run(j);
		p[i]=p[j];
	}
}uf;


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


