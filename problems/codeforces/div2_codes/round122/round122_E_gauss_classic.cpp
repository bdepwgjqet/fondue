/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/28/2012 02:11:08 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 1000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

int mt[7][6]={
	{0,0,1,0,1,1},
	{0,1,0,1,0,1},
	{0,1,1,1,1,0},
	{1,0,0,1,1,0},
	{1,0,1,1,0,1},
	{1,1,0,0,1,1},
	{1,1,1,0,0,0}
},b[7],x[7],mat[6][7],ansl;
char ret[7][5]={"aaab","aaba","aabb","abaa","abab","abba","abbb"};

void show()
{
	for(int j=0; j<6; j++)
	{
		for(int k=0; k<7; k++)
			printf("%d ",mat[j][k]);
		printf("%d\n",b[j]);
	}
	puts("");

}

int solve()
{
	int id;
	for(int i=0; i<6; i++)
	{
		//show();
		if(mat[i][i]==0)
		{
			id=-1;
			for(int j=i+1; j<6; j++)
				if(mat[j][i])
				{
					id=j;
					break;
				}
			if(id==-1)
				return 0;
			for(int j=0; j<7; j++)
				swap(mat[i][j],mat[id][j]);
			swap(b[id],b[i]);
		}
		int x=mat[i][i];
		for(int j=i; j<7; j++)
			if(mat[i][j]%x)
				return 0;
			else mat[i][j]/=x;
		if(b[i]%x) return 0;
		b[i]/=x;
		for(int j=0; j<6; j++)
		{
			if(j==i) continue;
			int d=mat[j][i];
			for(int k=i; k<7; k++)
				mat[j][k]-=d*mat[i][k];
			b[j]-=d*b[i];
		}
	}
	//show();
	int ans=100*inf,tmp,tag,xx;
	for(int i=0; i<inf; i++)
	{
		tmp=i;
		tag=1;
		for(int j=0; j<6; j++)
		{
			x[j]=b[j]-mat[j][6]*i;
			if(x[j]<0)
				tag=0;
			tmp+=x[j];
		}
		if(tag==0) continue;
		if(ans>tmp)
			ans=tmp,xx=i;
	}
	if(ans>=inf)
		return 0;
	for(int j=0; j<6; j++)
		x[j]=b[j]-mat[j][6]*xx;
	x[6]=xx;
	ansl=ans;
	return 1;
}

int main()
{
	for(int i=0; i<6; i++)
		for(int j=0; j<7; j++)
			mat[i][j]=mt[j][i];
	while(scanf("%d",&b[0])!=EOF)
	{
		for(int i=1; i<7; i++)
			scanf("%d",&b[i]);
		if(solve())
		{
			printf("%d\n",ansl);
			for(int i=0; i<4; i++,puts(""))
				for(int j=0; j<7; j++)
					for(int k=0; k<x[j]; k++)
						printf("%c",ret[j][i]);
		}
		else
			puts("-1");
	}
	return 0;
}
