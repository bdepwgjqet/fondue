// BEGIN CUT HERE

// END CUT HERE
#line 5 "RotatingBot.cpp"
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
#define N 2010
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

int mat[N][N];
struct node{ int x,y; }st,now;
int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}},l,r,h,b;

class RotatingBot
{
        public:
		int can(vector<int> moves,int n)
		{
			int x=0,y=0,d;
			st.x=st.y=1000;
			now.x=now.y=1000;
			memset(mat,0,sizeof(mat));
			mat[st.x][st.y]=1;
			for(int i=0; i<n; i++)
			{
				d=i%4;
				for(int j=1; j<=moves[i]; j++)
				{
					x=now.x+j*dir[d][0],y=now.y+j*dir[d][1];
					if(mat[x][y])
						return 0;
					mat[x][y]=1;
				}
				now.x=x,now.y=y;
			}
			return 1;
		}

		int inboard(int x,int y)
		{
			return l<=y&&y<=r&&h<=x&&x<=b;
		}

		int imp(vector<int> moves,int n)
		{
		//	printf("%d %d %d %d\n",l,r,h,b);
			int x=0,y=0,d;
			st.x=st.y=1000;
			now.x=now.y=1000;
			memset(mat,0,sizeof(mat));
			mat[st.x][st.y]=1;
			for(int i=0; i<n; i++)
			{
				d=i%4;
				for(int j=1; j<=moves[i]; j++)
				{
					x=now.x+j*dir[d][0],y=now.y+j*dir[d][1];
					mat[x][y]=1;
				}
				now.x=x,now.y=y;
				x=x+dir[d][0],y=y+dir[d][1];
		//		printf("%d %d %d %d=>\n",x,y,inboard(x,y),mat[x][y]);
				if(inboard(x,y)&&(!mat[x][y])&&(i+1<n))
					return 1;
			}
			return 0;
		}

        int minArea(vector <int> moves)
        {
			int n=moves.size();
			if(!can(moves,n))
				return -1;
			l=N,r=-N,h=N,b=-N;
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					if(mat[i][j])
					{
						l=min(j,l);
						r=max(j,r);
						h=min(h,i);
						b=max(b,i);
					}
			if(imp(moves,n))
				return -1;
			return (r-l+1)*(b-h+1);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, minArea(Arg0)); }
	void test_case_1() { int Arr0[] = {3,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(1, Arg1, minArea(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, minArea(Arg0)); }
	void test_case_3() { int Arr0[] = {9,5,11,10,11,4,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 132; verify_case(3, Arg1, minArea(Arg0)); }
	void test_case_4() { int Arr0[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420; verify_case(4, Arg1, minArea(Arg0)); }
	void test_case_5() { int Arr0[] = {8,6,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(5, Arg1, minArea(Arg0)); }
	void test_case_6() { int Arr0[] = {8,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 63; verify_case(6, Arg1, minArea(Arg0)); }
	void test_case_7() { int Arr0[] = {5,4,5,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(7, Arg1, minArea(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        RotatingBot ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
