//trie tree
//untest
#include <cstdio>
#include <cstring>
#define MAXN 100011
#define MAXC 11
int top;

int get_ind(char x){ return x-'0'; }
struct trie_node{ bool is; int n[MAXC]; }no[MAXN];

struct trie_tree
{
	trie_node r;
	trie_tree(){ r=no[0]; }
	void insert(char s[])
	{
		int i,l=strlen(s),p=0;
		for(i=0; i<l; i++)
		{
			if(no[p].n[get_ind(s[i])]<0)
			{
				no[top].is=0;
				no[p].n[get_ind(s[i])]=top++;
			}
			p=no[p].n[get_ind(s[i])];
		}
		no[p].is=1;
	}

	int search(char s[])
	{
		int i,l=strlen(s),p=0;
		for(i=0; i<l&&p!=-1; i++)
			p=no[p].n[get_ind(s[i])];
		return p!=-1&&no[p].is==1;
	}
}trie;

void init()
{
	int i,j;
	for(i=0; i<MAXN; i++)
		for(no[i].is=j=0; j<MAXC; j++)
			no[i].n[j]=-1;
	top=1;
}

int main()
{
	return 0;
}

