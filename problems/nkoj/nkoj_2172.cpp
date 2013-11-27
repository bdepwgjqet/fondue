#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#define N 1011

using namespace std;

struct node{ int l,r,i;
	friend int operator <(node a,node b){ return a.r==b.r?a.l>b.l:a.r<b.r; }
}no[N];

multiset<node> st;
multiset<node>::iterator it;
int turn;
char s[100];

int cmp(node a,node b){ return a.l==b.l?a.r<b.r:a.l>b.l; }

int main()
{
	int ts,n;
	scanf("%d",&ts);
	for(; ts--;)
	{
		st.clear();
		scanf("%d%s",&n,s);
		if(strcmp(s,"Petra")==0)
			turn=0;
		else
			turn=1;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&no[i].l,&no[i].r);
		}
		sort(no,no+n,cmp);
		int al=0,ar=0;
		for(int i=0; i<n; i++)
		{
			st.insert(no[i]);
			if(turn==0)
			{
				it=st.begin();
				al+=it->l;
				st.erase(it);
			}
			turn^=1;
		}
		for(it=st.begin(); it!=st.end(); it++)
			ar+=it->r;
		printf("%d %d\n",al,ar);
	}
	return 0;
}
