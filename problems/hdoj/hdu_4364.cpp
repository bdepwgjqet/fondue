#include <cstdio>
#define N 4
typedef unsigned int uint;

const uint smod=0x1B;
const uint MOD=0xFF;
uint mat[N][N],ret[N][N];
int mt[4][4]={{2,3,1,1},{1,2,3,1},{1,1,2,3},{3,1,1,2}};

uint mul(uint x,int i)
{
	uint y=x,ret;
	if(i==1)
		return x;
	if(i==2)
	{
		ret=(x<<1);
		if(ret>0xFF)
			return ret^smod;
		else
			return ret;
	}
	ret=(x<<1);
	if(ret>0xFF)
		ret^=smod;
	return ret^y;
}

void matrix_mul()
{
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			ret[i][j]=0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			for(int k=0; k<N; k++)
			{
				ret[i][j]^=mul(mat[k][j],mt[i][k]);
			}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(; t--; )
	{
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				scanf("%x",&mat[i][j]);
		matrix_mul();
		for(int i=0; i<4; i++)
		{
			printf("%02X",ret[i][0]&MOD);
			for(int j=1; j<4; j++)
				printf(" %02X",ret[i][j]&MOD);
			puts("");
		}
		if(t>0)
			puts("");
	}
	return 0;
}
