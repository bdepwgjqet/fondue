#include <cstdio>

char s[10][10];

int win(char x)
{
	for(int i=0; i<4; i++)
	{
		int tc=0,c=0;
		for(int j=0; j<4; j++)
		{
			if(s[i][j]==x)
				c++;
			else if(s[i][j]=='T')
				tc++;
		}
		if(c==4||(c==3&&tc==1))
			return 1;
	}
	for(int i=0; i<4; i++)
	{
		int tc=0,c=0;
		for(int j=0; j<4; j++)
		{
			if(s[j][i]==x)
				c++;
			else if(s[j][i]=='T')
				tc++;
		}
		if(c==4||(c==3&&tc==1))
			return 1;
	}
	int c=0,tc=0;
	for(int i=0; i<4; i++)
	{
		if(s[i][i]==x)
			c++;
		else if(s[i][i]=='T')
			tc++;
	}
	if(c==4||(c==3&&tc==1))
		return 1;
	c=0,tc=0;
	for(int i=0; i<4; i++)
	{
		if(s[i][3-i]==x)
			c++;
		else if(s[i][3-i]=='T')
			tc++;
	}
	if(c==4||(c==3&&tc==1))
		return 1;
	return 0;
}

int draw()
{
	int c=0;
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			if(s[i][j]=='.')
				c++;
	return (c==0);
}

void gao()
{
	if(win('X'))
		puts("X won");
	else if(win('O'))
		puts("O won");
	else if(draw())
		puts("Draw");
	else
		puts("Game has not completed");
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int ca=1; ca<=t; ca++)
	{
		printf("Case #%d: ",ca);
		for(int i=0; i<4; i++)
			scanf("%s",s[i]);
		gao();
	}
	return 0;
}
