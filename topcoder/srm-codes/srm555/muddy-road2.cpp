// BEGIN CUT HERE

// END CUT HERE
#line 5 "MuddyRoad2.cpp"
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
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 555555555
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

LL c[600][600];
LL dp[600][600][3];

class MuddyRoad2
{
        public:
        int theCount(int N, int muddyCount)
        {
			int cnt=muddyCount;
			c[0][0]=1;
			for(int i=1; i<600; i++)
			{
				c[i][0]=1;
				for(int j=1; j<=i; j++)
					c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
			}
			memset(dp,0,sizeof(dp));
			for(int i=1; i<=N-cnt; i++)
			{
				dp[i][1][i%3]=1;
				for(int j=2; j<=i; j++)
				{
					for(int k=1; k<=i; k++)
					{
						dp[i][j][k%3]=(dp[i][j][k%3]+dp[i-k][j-1][1]+dp[i-k][j-1][2])%MOD;
					}
				}
			}
			//printf("%lld %lld\n",dp[N-cnt][cnt+1][1],dp[N-cnt][cnt+1][2]);
			return ((c[N-2][cnt]-dp[N-cnt][cnt+1][2]-dp[N-cnt][cnt+1][1])%MOD+MOD)%MOD;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 2; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 65; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 314; int Arg1 = 78; int Arg2 = 498142902; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 555; int Arg1 = 222; int Arg2 = 541606281; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        MuddyRoad2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
