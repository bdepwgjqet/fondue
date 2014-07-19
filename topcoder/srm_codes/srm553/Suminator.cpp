// BEGIN CUT HERE

// END CUT HERE
#line 5 "Suminator.cpp"
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
#define N 101
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

LL dat[N],n,st[N]; int top;
int tag[N][N];

class Suminator
{
        public:
		int ok(int x)
		{
			top=-1;
			LL a,b;
			for(int i=0; i<n; i++)
			{
				if(dat[i]==0)
				{
					if(top<0)
						st[top=0]=0;
					else if(top==0)
					{
						st[top=0]=st[0];
					}
					else
					{
						a=st[top--];
						b=st[top--];
						st[++top]=a+b;
					}
				}
				else
				{
					st[++top]=dat[i];
				}
			}
			LL ret=-1;
			if(top<0)
				ret=0;
			else
				ret=st[top];
			return ret==x;
		}

		int solve(int x,int id)
		{
			top=-1;
			LL a,b;
			memset(tag,0,sizeof(tag));
			dat[id]=-1;
			for(int i=0; i<n; i++)
			{
				if(dat[i]==0)
				{
					if(top<0)
						st[top=0]=0;
					else if(top==0)
					{
						st[top=0]=st[0];
					}
					else
					{
						a=st[top--];
						b=st[top--];
						st[++top]=a+b;
						for(int j=0; j<=n; j++)
						{
							if(tag[top+1][j]||tag[top][j])
								tag[top][j]=1;
							tag[top+1][j]=0;
						}
					}
				}
				else
				{
					st[++top]=dat[i];
					tag[top][i]=1;
				}
			}
			LL ret=0;
			if(tag[top][id]==1)
			{
				ret=x-st[top]-1;
				if(ret<=0)
					return -1;
				return ret;
			}
			else
			{
				ret=st[top];
				if(ret!=x)
					return -1;
			}
			return -1;
		}

        int findMissing(vector <int> program, int wantedResult)
        {
			n=program.size();
			int id=-1;
			for(int i=0; i<n; i++)
			{
				dat[i]=program[i];
				if(program[i]==-1)
					id=i;
			}
			dat[id]=0;
			if(ok(wantedResult))
				return 0;
			return solve(wantedResult,id);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 200, 300, 0, 100, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 600; int Arg2 = 0; verify_case(1, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 7, 3, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 0; verify_case(2, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, 8, 4, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = -1; verify_case(3, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = -1; verify_case(4, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {7, -1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(5, Arg2, findMissing(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        Suminator ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
