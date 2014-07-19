// BEGIN CUT HERE

// END CUT HERE
#line 5 "XorBoardDivTwo.cpp"
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

class XorBoardDivTwo
{
        public:
        int theMax(vector <string> board)
        {
			int n=board.size(),m=board[0].length(),ttl=0;
			for(int i=0; i<n; i++)
				for(int j=0; j<m; j++)
					ttl+=board[i][j]-'0';
			int ret=0;
			for(int i=0; i<n; i++)
				for(int j=0; j<m; j++)
				{
					int tmp=0;
					for(int k=0; k<m; k++)
					{
						if(board[i][k]=='0')
							tmp++;
						else
							tmp--;
					}
					for(int k=0; k<n; k++)
					{
						if(board[k][j]=='0')
							tmp++;
						else
							tmp--;
					}
					if(board[i][j]=='0')
						tmp-=2;
					else
						tmp+=2;
					ret=max(ret,ttl+tmp);
				}
			return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"101",
 "010",
 "101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(0, Arg1, theMax(Arg0)); }
	void test_case_1() { string Arr0[] = {"111",
 "111",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, theMax(Arg0)); }
	void test_case_2() { string Arr0[] = {"0101001",
 "1101011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, theMax(Arg0)); }
	void test_case_3() { string Arr0[] = {"000",
 "001",
 "010",
 "011",
 "100",
 "101",
 "110",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(3, Arg1, theMax(Arg0)); }
	void test_case_4() { string Arr0[] = {"000000000000000000000000",
 "011111100111111001111110",
 "010000000100000001000000",
 "010000000100000001000000",
 "010000000100000001000000",
 "011111100111111001111110",
 "000000100000001000000010",
 "000000100000001000000010",
 "000000100000001000000010",
 "011111100111111001111110",
 "000000000000000000000000"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 105; verify_case(4, Arg1, theMax(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        XorBoardDivTwo ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
