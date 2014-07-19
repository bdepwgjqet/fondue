// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheBrickTowerMediumDivOne.cpp"
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

vector<int> ret;
int vis[N];

class TheBrickTowerMediumDivOne
{
        public:
        vector <int> find(vector <int> heights)
        {
			int n=heights.size();
			ret.clear();
			ret.push_back(0);
			memset(vis,0,sizeof(vis));
			vis[0]=1;
			for(;;)
			{
				int i;
				for(i=0; i<n; i++)
				{
					if(!vis[i]&&(heights[i]<=heights[ret[ret.size()-1]]))
						break;
				}
				if(i>=n) break;
				ret.push_back(i);
				vis[i]=1;
			}
			for(;;)
			{
				int i,k=-1;
				for(i=0; i<n; i++)
					if(!vis[i]&&(k==-1||heights[i]<heights[k]))
						k=i;
				if(k==-1) break;
				ret.push_back(k);
				vis[k]=1;
			}
			return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {4, 7, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 4, 4, 4, 4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 3, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arr0[] = {13, 32, 38, 25, 43, 47, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 6, 3, 1, 2, 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TheBrickTowerMediumDivOne ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
