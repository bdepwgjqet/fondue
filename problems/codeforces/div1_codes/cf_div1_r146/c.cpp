#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2000100
#define X 26

using namespace std;

struct node {
	int f,l,num,nx[X],flag;
	node() {
		f=-1,l=0,num=0,flag=-1;
		for(int i=0; i<X; i++) {
			nx[i]=-1;
		}
	}
}no[N];

int T,tail,head,top;
char s[N],qs[N];
vector<int> vec[N];

void insert(int x,int l) {
	int p=tail,q=top++;
	tail=q;
	no[q].l=l;
	no[q].num=1;
	while(p!=-1 && no[p].nx[x]==-1) {
		no[p].nx[x]=q;
		p=no[p].f;
	}
	if(p==-1) {
		no[q].f=head;
		return;
	}
	if(no[no[p].nx[x]].l==no[p].l+1) {
		no[q].f=no[p].nx[x];
		return;
	}
	int u=top++,np=no[p].nx[x];
	no[u]=no[np];
	no[u].num=0;
	no[u].l=no[p].l+1;
	no[np].f=no[q].f=u;
	for(; p!=-1 && no[p].nx[x]==np; p=no[p].f) {
		no[p].nx[x]=u;
	}
}

void build_sam(char s[]) {
	int l=strlen(s);
	tail=head=0;
	top=1;
	for(int i=0; i<l; i++) {
		insert(s[i]-'a',i+1);
	}
}

int query(char qs[]) {
	int len=strlen(qs);
	int ret=0;
	for(int i=0; i<len; i++)
		qs[len+i]=qs[i];
	qs[len+len]=0;
	int now=head,nowl=0;
	for(int i=0; i<len+len; i++) {
		int x=qs[i]-'a';
		while(now!=-1 && no[now].nx[x]==-1) {
			now=no[now].f;
			nowl=now>=0?no[now].l:0;
		}
		if(now==-1) {
			now=head;
			nowl=0;
			continue;
		}
		now=no[now].nx[x];
		nowl++;
		if(nowl>=len) {
			int p=now;
			for(; no[p].f>=0 && no[no[p].f].l>=len;)
				p=no[p].f;
			if(no[p].flag!=T) {
				no[p].flag=T;
				ret+=no[p].num;
			}
		}
	}
	return ret;
}

int main() {
	scanf("%s",s);
	build_sam(s);
	for(int i=0; i<top; i++) {
		vec[no[i].l].push_back(i);
	}
	for(int i=N-1; i>=0; i--) {
		for(int j=0; j<vec[i].size(); j++) {
//		for(int j=vec[i].size()-1; j>=0; j--) {
			int x=vec[i][j];
			if(no[x].f>=0)
				no[no[x].f].num+=no[x].num;
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=0; i<q; i++) {
		scanf("%s",qs);
		T=i;
		printf("%d\n",query(qs));
	}
	return 0;
}
