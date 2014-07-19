// BEGIN CUT HERE

// END CUT HERE
#line 5 "SafeRemoval.cpp"
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int dp[51][51][51][51];
int dat[N],ret,n,sum[4][51],num[4];
int cmp(int a,int b){ return a>b; }

class SafeRemoval
{
        public:
		int dfs(int now,int a,int b,int c,int d,int k)
		{
			int res=0;
			if(dp[a][b][c][d]>=0)
				return dp[a][b][c][d];
			if((b*1+c*2+d*3)%4==0)
				return dp[a][b][c][d]=0;
			if(now==k)
			{
				ret=max(ret,sum[0][a]+sum[1][b]+sum[2][c]+sum[3][d]);
				return dp[a][b][c][d]=1;
			}
			if(a>0)
				res=max(dfs(now+1,a-1,b,c,d,k),res);
			if(b>0)
				res=max(dfs(now+1,a,b-1,c,d,k),res);
			if(c>0)
				res=max(dfs(now+1,a,b,c-1,d,k),res);
			if(d>0)
				res=max(dfs(now+1,a,b,c,d-1,k),res);
			return dp[a][b][c][d]=res;
		}

        int removeThem(vector <int> seq, int k)
        {
			n=seq.size();
			memset(dp,-1,sizeof(dp));
			for(int i=0; i<seq.size(); i++)
				dat[i]=seq[i];
			sort(dat,dat+n,cmp);
			for(int i=0; i<4; i++)
				sum[i][0]=0,num[i]=0;
			for(int i=0; i<n; i++)
			{
				int x=dat[i]%4;
				sum[x][num[x]+1]=sum[x][num[x]]+dat[i];
				num[x]++;
			}
			ret=0;
			if(dfs(0,num[0],num[1],num[2],num[3],k))
			{
				return ret;
			}
			else
				return -1;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 11; verify_case(0, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(1, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,6,1,10,1,2,7,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 21; verify_case(2, Arg2, removeThem(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(3, Arg2, removeThem(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        SafeRemoval ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
