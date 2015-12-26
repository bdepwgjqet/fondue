// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysFigurines.cpp"
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

char s[20][20];
int m,n;

class EllysFigurines
{
        public:
		inline int B(int i){ return 1<<i; }

		int r[20],c[20],tmp[20];

        int getMoves(vector <string> board, int R, int C)
        {
			int m=board.size(),n=board[0].length();
			for(int i=0; i<m; i++)
				for(int j=0; j<n; j++)
					s[i][j]=board[i][j];
			int ret=N;
			for(int st=0; st<B(m); st++)
			{
				int now=0;
				memset(r,0,sizeof(r));
				memset(c,0,sizeof(c));
				memset(tmp,0,sizeof(tmp));
				for(int u=0; u<m; u++)
					if(st&B(u))
						tmp[u]=1,now++;
				for(int i=0; i<m; i++)
					if(tmp[i]==1)
						for(int j=i; j<i+R&&j<m; j++)
							r[j]=1;
				for(int i=0; i<n; i++)
				{
					int tag=0;
					for(int j=0; j<m; j++)
						if(s[j][i]=='X'&&r[j]==0)
							tag=1;
					if(tag) c[i]=1;
				}
				for(int i=0; i<n; i++)
					if(c[i])
						now++,i+=C-1;
				ret=min(ret,now);
			}
			return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if((Case == -1) || (Case==5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 3; verify_case(0, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; verify_case(1, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"XXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 1; verify_case(2, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 4; verify_case(3, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"XXX..XXX..XXX.",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X...XXX..XXX.",
 "..............",
 "...XX...XXX...",
 "....X......X..",
 "....X....XXX..",
 "....X......X..",
 "...XXX..XXX..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 7; verify_case(4, Arg3, getMoves(Arg0, Arg1, Arg2)); }

	void test_case_5()
	{
		string Arr0[] = {
			 ".X.X.X.X.X.X.X.",
			 "XXXXXXXXXXXXXXX",
			 ".X.X.X.X.X.X.X.",
			 "XXXXXXXXXXXXXXX",
			 ".X.X.X.X.X.X.X.",
			 "XXXXXXXXXXXXXXX",
			 ".X.X.X.X.X.X.X.",
			 "XXXXXXXXXXXXXXX",
			 ".X.X.X.X.X.X.X.",
			 "XXXXXXXXXXXXXXX",
			 ".X.X.X.X.X.X.X.",
			 "XXXXXXXXXXXXXXX",
			 ".X.X.X.X.X.X.X.",
			 "XXXXXXXXXXXXXXX",
			 ".X.X.X.X.X.X.X."};
		vector <string> Arg0(Arr0,Arr0+((sizeof(Arr0))/sizeof(Arr0[0])));
		int Arg1 = 1;
		int Arg2 = 1;
		int Arg3 = 14;
		verify_case(5,Arg3,getMoves(Arg0,Arg1,Arg2));
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        EllysFigurines ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
