// BEGIN CUT HERE

// END CUT HERE
#line 5 "HouseBuilding.cpp"
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

string s;
int dp[2555][11][11];

class HouseBuilding
{
        public:
		int gao(int id,int l,int r)
		{
			if(dp[id][l][r]>=0)
				return dp[id][l][r];
			if(id==s.size())
				return dp[id][l][r]=0;
			int x=s[id]-'0',ret=100000000;
			if(l==10)
			{
				for(int i=0; i<10; i++)
					ret=min(ret,gao(id+1,i,i)+abs(x-i));
			}
			else if(l==r)
			{
				ret=min(ret,gao(id+1,l,l)+abs(x-l));
				if(l<9)
					ret=min(ret,gao(id+1,l,l+1)+abs(x-l-1));
				if(l>0)
					ret=min(ret,gao(id+1,l-1,l)+abs(x-l+1));
			}
			else
			{
				ret=min(ret,gao(id+1,l,r)+abs(x-l));
				ret=min(ret,gao(id+1,l,r)+abs(x-r));
			}
			return dp[id][l][r]=ret;
		}

        int getMinimum(vector <string> area)
        {
			s.clear();
			for(int i=0; i<area.size(); i++)
				s+=area[i];
			memset(dp,-1,sizeof(dp));
			return gao(0,10,10);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10",
 "31"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { string Arr0[] = {"54454",
 "61551"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { string Arr0[] = {"989"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { string Arr0[] = {"90"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { string Arr0[] = {"5781252",
 "2471255",
 "0000291",
 "1212489"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 53; verify_case(4, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        HouseBuilding ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
