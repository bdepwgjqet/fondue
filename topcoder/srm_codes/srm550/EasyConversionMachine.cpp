// BEGIN CUT HERE

// END CUT HERE
#line 5 "EasyConversionMachine.cpp"
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

class EasyConversionMachine
{
        public:
        string isItPossible(string originalWord, string finalWord, int k)
        {
			int n=originalWord.length();
			int d=0;
			for(int i=0; i<n; i++)
				if(originalWord[i]!=finalWord[i])
					d++;
			if(d>k)
				return "IMPOSSIBLE";
			if((k-d)%2)
				return "IMPOSSIBLE";
			return "POSSIBLE";
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aababba"; string Arg1 = "bbbbbbb"; int Arg2 = 2; string Arg3 = "IMPOSSIBLE"; verify_case(0, Arg3, isItPossible(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "aabb"; string Arg1 = "aabb"; int Arg2 = 1; string Arg3 = "IMPOSSIBLE"; verify_case(1, Arg3, isItPossible(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "aaaaabaa"; string Arg1 = "bbbbbabb"; int Arg2 = 8; string Arg3 = "POSSIBLE"; verify_case(2, Arg3, isItPossible(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "aaa"; string Arg1 = "bab"; int Arg2 = 4; string Arg3 = "POSSIBLE"; verify_case(3, Arg3, isItPossible(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "aababbabaa"; string Arg1 = "abbbbaabab"; int Arg2 = 9; string Arg3 = "IMPOSSIBLE"; verify_case(4, Arg3, isItPossible(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        EasyConversionMachine ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
