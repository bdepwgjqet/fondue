#include <cstdio>
#define MAXN 60

//�����: ��ȡ�õ�����k���㹹����ȫͼ
//��������Ŵ�С��һ������,����ͼ�Ĵ�Сn���ڽ���mat
//mat[i][j]Ϊ������
//n:u[]��Ԫ�ظ���, u[]���뵱ǰ�����ӵĵ�, bb ��־...�ݹ����, c[]����������Ŵ�С
//size:��ǰclique��С, max��ǰclique���ֵ, res[]��¼����һ�������,rr[]��ǰ�ŵĽ��
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