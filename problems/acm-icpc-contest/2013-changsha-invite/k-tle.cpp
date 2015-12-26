#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <utility>

using namespace std;
const int N = 20022;
const double inf = 1e10;

vector<pair<int,int> > tr[N];
vector<int> tmp[N];

int n,L,len[N],grp[N];
double dp[N],dp1[N],dp2[N];

map<int,int> mp;
map<int,int> mps[N];

void dfs(int now,int p) {
	for(int i=0; i<tr[now].size(); i++) {
		int to=tr[now][i].first;
		int l=tr[now][i].second;
		if(p!=to) {
			len[to]=len[now]+l;
			grp[to]=(now==0?to:grp[now]);
			dfs(to,now);
		}
	}
}

double qt(double x) {
	return x*x;
}

double y(int i,int tag) {
	return dp[i]+sqrt(dp[i])+1.0*len[i]*len[i]+tag*2.0*L*len[i];
}

double getk(int i,int j,int tag) {
	return (y(i,tag)-y(j,tag))/(len[i]-len[j]);
}

double _xmult(double x1,double y1,double x2,double y2) {
	return x1*y2-x2*y1;
}

double xmult(int i,int j,int k,int tag) {
	return _xmult(len[j]-len[i],y(j,tag)-y(i,tag),len[k]-len[j],y(k,tag)-y(j,tag));
}

double get_val(int i,int j) {
	return dp[i]+sqrt(dp[i])+qt(abs(len[j]-len[i])-L);
}

void gao1(int now,int p) {
	for(int i=0; i<tr[now].size(); i++) {
		int to=tr[now][i].first;
		int l=tr[now][i].second;
		if(to==p) continue;
		tmp[now].clear();
		for(;mp.size()>=2;) {
			if(getk((++mp.begin())->second,mp.begin()->second,1)<=2.0*len[to]) {
				tmp[now].push_back(mp.begin()->second);
				mp.erase(mp.begin());
			}
			else
				break;
		}
		for(; mp.size()>=2;) {
			if(xmult((++mp.rbegin())->second,mp.rbegin()->second,to,1)<=0) {
				tmp[now].push_back(mp.rbegin()->second);
				mp.erase((--mp.end()));
			}
			else
				break;
		}
		dp[to]=get_val(mp.rbegin()->second,to);
		mp[len[to]]=to;
		gao1(to,now);
		mp.erase((--mp.end()));
		for(int j=0; j<tmp[now].size(); j++) {
			int x=tmp[now][j];
			mp[len[x]]=x;
		}
	}
	if(tr[now].size()==1) {
		dp1[grp[now]]=min(dp1[grp[now]],dp[now]);
	}
}

double get_v(int i,int now) {
	if(mps[i].size()<=0) return 0;
	for(; mps[i].size()>=2;) {
		if(getk(mps[i].rbegin()->second,(++mps[i].rbegin())->second,-1)>=2*len[now])
			mps[i].erase((--mps[i].end()));
		else
			break;
	}
	dp[now]=get_val(mps[i].rbegin()->second,now);
	for(; mps[i].size()>=2;) {
		if(xmult(now,mps[i].begin()->second,(++mps[i].begin())->second,-1)<=0)
			mps[i].erase(mps[i].begin());
		else
			break;
	}
	return dp[now];
}

void merge(int i,int j) {
	if(mps[i].size()<mps[j].size()) {
		merge(j,i);
		mps[i]=mps[j];
	}
	for(; mps[j].size()>0;) {
		int now=mps[j].begin()->second;
		mps[j].erase(mps[j].begin());
		if(mps[i].count(len[now])>0) {
			if(y(now,-1)>=y(mps[i][len[now]],-1))
				continue;
		}
		mps[i][len[now]]=now;
		if(mps[i].size()<=2) continue;
		map<int,int>::iterator it=mps[i].find(len[now]),l,r;
		if(it!=(--mps[i].end())&&it!=mps[i].begin()) {
			l=it,l--;
			r=it,r++;
			if(xmult(l->second,it->second,r->second,-1)<=0) {
				mps[i].erase(it);
				continue;
			}
		}
		for(; it!=(++mps[i].begin())&&it!=mps[i].begin();) {
			r=it,r--;
			l=r,l--;
			if(xmult(l->second,r->second,it->second,-1)<=0) {
				mps[i].erase(r);
			}
			else break;
		}
		for(; it!=(--mps[i].end())&&it!=(--(--mps[i].end()));) {
			l=it,l++;
			r=l,r++;
			if(xmult(it->second,l->second,r->second,-1)<=0) {
				mps[i].erase(l);
			}
			else break;
		}
	}
}

void gao2(int now,int p) {
	mps[now].clear();
	for(int i=0; i<tr[now].size(); i++) {
		int to=tr[now][i].first;
		int l=tr[now][i].second;
		if(to==p) 
			continue;
		gao2(to,now);
		if(now==0) {
			dp2[to]=min(dp2[to],get_v(to,now));
		}
		else {
			merge(now,to);
		}
	}
	if(now==0) return;
	if(tr[now].size()==1) {
		dp[now]=0;
	} else {
		dp[now]=get_v(now,now);
	}
	mps[now][len[now]]=now;
}

int main() {
	while(scanf("%d%d",&n,&L)+1) {
		for(int i=0; i<n; i++) {
			tr[i].clear();
			dp1[i]=inf;
			dp2[i]=inf;
			len[i]=0;
		}
		for(int i=0; i<n-1; i++) {
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			tr[x-1].push_back(make_pair(y-1,z));
			tr[y-1].push_back(make_pair(x-1,z));
		}
		if(tr[0].size()<=1) {
			puts("-1");
			continue;
		}
		dfs(0,-1);
		mp.clear();
		mp[0]=0;
		dp[0]=0;
		gao1(0,-1);
		mp.clear();
		gao2(0,-1);
		double mi1=inf,mi2=inf,mid;
		for(int i=0; i<tr[0].size(); i++) {
			int to=tr[0][i].first;
			if(dp2[to]<mi1) {
				mi2=mi1;
				mi1=dp2[to];
				mid=to;
			} else if(dp2[to]<mi2) {
				mi2=dp2[to];
			}
		}
		double ret=inf;
		for(int i=0; i<tr[0].size(); i++) {
			int to=tr[0][i].first;
			if(to==mid)
				ret=min(ret,dp1[to]+mi2);
			else
				ret=min(ret,dp1[to]+mi1);
		}
		printf("%.2f\n",ret);
	}
	return 0;
}
