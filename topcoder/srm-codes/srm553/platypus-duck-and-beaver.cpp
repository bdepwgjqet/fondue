// BEGIN CUT HERE

// END CUT HERE
#line 5 "PlatypusDuckAndBeaver.cpp"
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

class PlatypusDuckAndBeaver
{
        public:
        int minimumAnimals(int webbedFeet, int duckBills, int beaverTails)
        {
			int f=webbedFeet,d=duckBills,b=beaverTails;
			int tf,td,tb;
			int a,bb,c;
			for(int i=0; 4*i<=f; i++)
			{
				tf=f-4*i,td=d-i,tb=b-i;
				if(2*td+4*tb==tf)
				{
					a=td,bb=tb,c=i;
					break;
				}
			}
			return a+bb+c;
        }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(1, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 2; int Arg3 = 3; verify_case(2, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 60; int Arg1 = 10; int Arg2 = 10; int Arg3 = 20; verify_case(3, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 200; int Arg2 = 200; int Arg3 = 300; verify_case(4, Arg3, minimumAnimals(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        PlatypusDuckAndBeaver ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
