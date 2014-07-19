#include <cstdio>
#define MAXN 60

//最大团: 能取得的最大的k个点构成完全图
//返回最大团大小和一个方案,传入图的大小n和邻接阵mat
//mat[i][j]为布尔量
//n:u[]中元素个数, u[]存与当前点连接的点, bb 标志...递归出口, c[]各个点最大团大小
//size:当前clique大小, max当前clique最大值, res[]记录其中一个最大团,rr[]当前团的结点
void clique(int n,int u[],int mat[][MAXN],int size,int& max,int& bb,int res[],int rr[],int c[]) 
{
	int i,j,vn,v[MAXN];
	if(n) 
    {
		if(size+c[u[0]]<=max)   return;
		for(i=0; i<n+size-max && i<n; ++i)
        {
			for(j=i+1,vn=0; j<n; ++j)
				if(mat[u[i]][u[j]])
					v[vn++]=u[j];
			rr[size]=u[i];
			clique(vn,v,mat,size+1,max,bb,res,rr,c);
			if(bb)              return;
		}
	}
    else if(size>max)
    {
		max=size;
		for(i=0; i<size; ++i)
			res[i]=rr[i];
		bb=1;
	}
}

int maxclique(int n,int mat[][MAXN],int ret[])
{
	int max=0,bb,c[MAXN],i,j,vn,v[MAXN],rr[MAXN];
	for(c[i=n-1]=0; i>=0; --i) 
    {
		for(vn=0,j=i+1; j<n; ++j)
			if(mat[i][j])
			    v[vn++]=j;
		bb=0, rr[0]=i;				
		clique(vn,v,mat,1,max,bb,ret,rr,c);
		c[i]=max;
	}
	return max;
}
