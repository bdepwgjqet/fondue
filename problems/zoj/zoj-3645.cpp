#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define eps 1e-6

using namespace std;

struct node{ double x[12]; }no[12];
double mat[166][12];
int top=0;

int solve()
{
	for(int i=0; i<11; i++)
	{
		int id=-1;
		for(int j=i; j<top; j++)
			if(fabs(mat[i][j])>0)
			{
				id=j;
				break;
			}
		if(id==-1)
			return 0;
		for(int j=0; j<12; j++)
			swap(mat[i][j],mat[id][j]);
		for(int j=i+1; j<12; j++)
			mat[i][j]/=mat[i][i];
		mat[i][i]=1.0;
		for(int k=0; k<top; k++)
		{
			if(k==i)
				continue;
			if(fabs(mat[k][i])>0)
			{
				for(int j=11; j>=i; j--)
					mat[k][j]-=mat[i][j]*mat[k][i];
			}
		}
	}
	return 1;
}

int main()
{
	int n,ts;
	scanf("%d",&ts);
	for(; ts--;)
	{
		memset(mat,0,sizeof(mat));
		top=0;
		for(int i=0; i<12; i++)
		{
			for(int j=0; j<12; j++)
			{
				scanf("%lf",&no[i].x[j]);
			}
		}
		for(int i=0; i<12; i++)
		{
			for(int j=i+1; j<12; j++)
			{
				for(int k=0; k<11; k++)
				{
					mat[top][k]=-2*no[i].x[k]+2*no[j].x[k];
					mat[top][11]-=no[i].x[k]*no[i].x[k]-no[j].x[k]*no[j].x[k];
				}
				mat[top][11]+=no[i].x[11]*no[i].x[11]-no[j].x[11]*no[j].x[11];
				top++;
			}
		}
		int tag=solve();
		if(tag==0)
			for(;;);
		for(int i=0; i<11; i++)
			if(fabs(mat[i][11])<eps)
				mat[i][11]=0.0;
		printf("%.2lf",mat[0][11]);
		for(int i=1; i<11; i++)
			printf(" %.2lf",mat[i][11]);
		puts("");
	}
	return 0;
}
