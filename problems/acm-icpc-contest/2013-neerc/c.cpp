#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 2000000;

struct node {
	int val;
	int next;
	void ini() {
		next=-1;
		val=0;
	}
}no[N];

int le[N],re[N],top,tp;
char ss[100];

void add_le(int now,int v) {
	no[top].val=v;
	no[top].next=le[now];
	le[now]=top++;
}

void add_re(int now,int v) {
	no[top].val=v;
	no[top].next=re[now];
	re[now]=top++;
}

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m)+1) {
		top=0,tp=2;
		for(int i=0; i<n+2; i++) {
			le[i]=-1;
			re[i]=-1;
			no[i].ini();
		}
		for(int i=0; i<n; i++) {
			scanf("%s",ss);
			if(strcmp(ss,"learn")==0) {
				int c,p;
				scanf("%d%d",&c,&p);
				add_le(c,p);
			}
			else if(strcmp(ss,"rollback")==0) {
				int c;
				scanf("%d",&c);
				add_re(c,no[le[c]].val);
				le[c]=no[le[c]].next;
			}
			else if(strcmp(ss,"relearn")==0) {
				int c;
				scanf("%d",&c);
				add_le(c,no[re[c]].val);
				re[c]=no[re[c]].next;
			}
			else if(strcmp(ss,"clone")==0) {
				int x;
				scanf("%d",&x);
				le[tp]=le[x];
				re[tp++]=re[x];
			}
			else {
				int c;
				scanf("%d",&c);
			//	printf("%d\n",le[c]);
				if(le[c]==-1)
					puts("basic");
				else
					printf("%d\n",no[le[c]].val);
			}
		}
	}
	return 0;
}
