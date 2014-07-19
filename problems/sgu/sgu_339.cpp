#include <cstdio>
#define N 1101

struct seg{ int x,y; }sg[N];
char s[20];
int top;

int main()
{
	top=0;
	int x,y;
	while(scanf("%s%d%d",s,&x,&y)+1)
	{
		if(s[0]=='+')
		{
			int ret=0;
			for(int i=0; i<top; i++)
				if(sg[i].x>=x&&sg[i].y<=y)
					ret++;
			sg[top].x=x,sg[top++].y=y;
			printf("%d\n",ret);
		}
		else
		{
			int id=-1;
			for(int i=top-1; i>=0; i--)
				if(sg[i].x==x&&sg[i].y==y)
				{
					id=i;
					break;
				}
			if(id>=0)
			{
				for(int i=id; i+1<top; i++)
					sg[i]=sg[i+1];
				top--;
			}
		}
	}
	return 0;
}
