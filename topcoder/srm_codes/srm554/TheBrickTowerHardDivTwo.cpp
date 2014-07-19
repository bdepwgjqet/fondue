// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheBrickTowerHardDivTwo.cpp"
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
#define MOD 1234567891 
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

LL dp[50][10][400],rr;
int c,k,h;

LL dfs(int l,int us,int pre)
{
	int p[4];
	if(dp[l][us][pre]>=0)
		return dp[l][us][pre];
	if(l==h)
		return dp[l][us][pre]=1;
	if(pre==399)
	{
		for(int i=0; i<4; i++)
			p[i]=-1;
	}
	else
	{
		int y=pre;
		for(int i=3; i>=0; i--)
			p[i]=y%c,y/=c;
	}
	int ii[4];
	LL ret=0;
	if(pre==399)
		rr=(rr+dfs(l+1,0,399))%MOD;
	for(ii[0]=0; ii[0]<c; ii[0]++)
		for(ii[1]=0; ii[1]<c; ii[1]++)
			for(ii[2]=0; ii[2]<c; ii[2]++)
				for(ii[3]=0; ii[3]<c; ii[3]++)
				{
					int cnt=0,now=0;
					for(int i=0; i<4; i++)
					{
						if(ii[i]==p[i])
							cnt++;
						now*=c,now+=ii[i];
					}
					if(ii[0]==ii[1]) cnt++;
					if(ii[0]==ii[2]) cnt++;
					if(ii[1]==ii[3]) cnt++;
					if(ii[2]==ii[3]) cnt++;
					if(us+cnt>k)
						continue;
					ret=(ret+dfs(l+1,us+cnt,now))%MOD;
				}
	return dp[l][us][pre]=ret;
}

class TheBrickTowerHardDivTwo
{
        public:
        int find(int C, int K, int H)
        {
			c=C,k=K;
			h=H;
			rr=0;
			memset(dp,-1,sizeof(dp));
			return ((rr+dfs(0,0,399)-1)%MOD+MOD)%MOD;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 2; int Arg3 = 4; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 7; int Arg2 = 19; int Arg3 = 1; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1; int Arg3 = 14; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 47; int Arg3 = 1008981254; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TheBrickTowerHardDivTwo ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
