/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/31/2012 07:34:36 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define inf 0x7fffffff
#define N 1010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char s[N];
string equ[N];
int vis[N],cnt;
map<string,int> var;

void cls_space(int &i,int l,char s[])
{
	for(; i<l&&s[i]==' '; i++);
}

inline int get_tag(char x)
{
	if(x=='+')
		return 0;
	if(x=='-')
		return 1;
	if(x=='*')
		return 2;
	if('('==x)
		return 3;
	if(')'==x)
		return 4;
	if('0'<=x&&x<='9')
		return 5;
	return 6;
}

int tmp_pop(int tag,int a,int b)
{
	if(tag==2)
		a=a*b;
	else if(tag==1)
		a=b-a;
	else
		a=a+b;
	return a;
}

int dfs(string x)
{
	if(var.find(x)==var.end())
		return inf;
	int id=var[x],flag,tag,l=equ[id].size(),z_k=0;
	if(vis[id])
		return inf;
	vis[id]=1;
	vector<int> u;
	vector<int> v;
	string tmp;
	for(int i=0; i<l; )
	{
		for(; i<l&&equ[id][i]==' '; i++);
		if(i>=l)	break;
		tag=get_tag(equ[id][i]);
		tmp=string("");
		flag=1;
		if((tag==1&&u.size()!=v.size()-z_k+1)||tag>=5)
		{
			if(tag==1)	i++,tag=5,flag=-1;
			for(; i<l&&equ[id][i]!=' '&&get_tag(equ[id][i])>=5; i++)
				tmp+=equ[id][i];
		}
		else
			tmp+=equ[id][i++];
//		cout<<tmp<<endl;
//		cout<<tag<<endl;
		if(tag<=3)
		{
			for(int j=v.size()-1; j>=0; j--)
			{
				if((tag<=v[j]&&v[j]<3)||(tag==1&&v[j]==0))
				{
					int a=u.back();
					u.pop_back();
					int b=u.back();
					u.pop_back();
//					cout<<a<<" "<<b<<" "<<v[j]<<endl;
					a=tmp_pop(v[j],a,b);
					u.push_back(a);
					v.pop_back();
				}
				else
					break;
			}
			if(tag==3)
				z_k++;
			v.push_back(tag);
		}
		else if(tag==4)
		{
			for(int j=v.size()-1; j>=0; j--)
			{
				if(v[j]==3)
					break;
				int a=u.back();
				u.pop_back();
				int b=u.back();
				u.pop_back();
				//cout<<a<<" "<<b<<" "<<v[j]<<endl;
				a=tmp_pop(v[j],a,b);
				u.push_back(a);
				v.pop_back();
			}
			z_k--;
			v.pop_back();
		}
		else if(tag==5)
		{
			int ret=0;
			for(int j=0; j<tmp.length(); j++)
				ret*=10,ret+=tmp[j]-'0';
			u.push_back(ret*flag);
		}
		else 
		{
			int ret=dfs(tmp);
			if(ret==inf)	
			{
				vis[id]=0;
				return inf;
			}
			u.push_back(ret);
		}
	}
	for(int j=v.size()-1; j>=0; j--)
	{
		int a=u.back();
		u.pop_back();
		int b=u.back();
		u.pop_back();
		a=tmp_pop(v[j],a,b);
		u.push_back(a);
		v.pop_back();
	}
	vis[id]=0;
	return u.back();
}

void show(string x)
{
	memset(vis,0,sizeof(vis));
	int ret=dfs(x);
	if(ret<inf)
		printf("%d\n",ret);
	else
		puts("UNDEF");
}

int main()
{
	int i,l;
	string reset=string("RESET");
	string print=string("PRINT");
	string first;
	string tmp;
	cnt=0;
	while(gets(s)!=NULL)
	{
		if(s[0]=='\0')
			continue;
		i=0;
		l=strlen(s);
		cls_space(i,l,s);
		first=string("");
		for(; i<l&&s[i]!=' '&&s[i]!=':'; i++)
			first+=s[i];
		if(first==reset)
		{
			cnt=0;
			var.clear();
		}
		else if(first==print)
		{
			cls_space(i,l,s);
			tmp=string("");
			for(; i<l&&s[i]!=' '; i++)
				tmp+=s[i];
			show(tmp);
		}
		else
		{
			if(var.find(first)==var.end())
				var[first]=cnt++;
			tmp=string("");
			for(; i<l&&s[i]!=':'; i++);
			i+=2;
			cls_space(i,l,s);
			for(; i<l; i++)
				tmp+=s[i];
			int id=var[first];
			equ[id]=tmp;
		}
	}
	return 0;
}
