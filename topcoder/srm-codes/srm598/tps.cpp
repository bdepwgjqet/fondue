// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Treeland has N cities, numbered 0 through N-1.
There are N-1 undirected roads, each connecting a pair of cities.
The roads form a tree.
(I.e., each pair of cities is connected via some sequence of roads.)


You are given a string linked with N elements, each consisting of N characters.
There is a road between city i and city j if and only if linked[i][j] is 'Y'.
In all other cases linked[i][j] is 'N'.


The inhabitants of Treeland want to create the Treeland Positioning System (TPS).
TPS will be a system that will help people determine which city they are in.
The system will consist of K labeled beacons.
Each beacon will be located in one of the cities.
When a person turns on their TPS receiver, it will determine its distance to each of the beacons.
(The distance is measured as the number of roads the person would have to use in order to reach the beacon.)


Obviously, TPS will only be usable if different cities correspond to different readings on the receiver.
In other words, the number K and the placement of beacons must be such that there are no two cities where the receiver will report the same sequence of values.
(Note that the beacons can be distinguished. See Example 1.)


Return the minimal possible value of K.

DEFINITION
Class:TPS
Method:minimalBeacons
Parameters:vector <string>
Returns:int
Method signature:int minimalBeacons(vector <string> linked)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-linked will contain N elements.
-Each element of linked will contain N characters.
-Each character of each element of linked will be either 'Y' or 'N'.
-For each i and j, if linked[i][j] is 'Y' then linked[j][i] is 'Y'.
-For each i, linked[i][i] will be 'N'.
-The graph described by linked will be a tree with N nodes.


EXAMPLES

0)
{"NYNN",
 "YNYN",
 "NYNY",
 "NNYN"}

Returns: 1

There are 4 cities and 3 roads: 0-1-2-3.
One possible solution is to put a beacon in city 0. Then city i will have distance i from that beacon, and they are distinguishable.

1)
{"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"}

Returns: 2

There are also 4 cities. The road network looks as follows:

1 - 0 - 2
    |
    3

1 beacon is not enough, for example:

If it is located in city 0, then cities 1,2 and 3 all have distance 1 from that beacon, they are not distinguishable.
If it is located in city 1, then cities 2, 3 all have distance 2 from that beacon, they are not distinguishable.

2 beacons are enough. For example, we can place them into cities 1 and 2. Then:

If we are in city 0 the receiver will show the distances 1, 1.
If we are in city 1 the receiver will show the distances 0, 2.
If we are in city 2 the receiver will show the distances 2, 0.
If we are in city 3 the receiver will show the distances 2, 2.

In each city the receiver shows a different sequence of distances.


2)
{"NNYNNNNNNN",
 "NNNNNYNNNN",
 "YNNYNNYNNN",
 "NNYNYNNYNN",
 "NNNYNYNNYN",
 "NYNNYNNNNY",
 "NNYNNNNNNN",
 "NNNYNNNNNN",
 "NNNNYNNNNN",
 "NNNNNYNNNN"}


Returns: 2

The graph looks as follows:

0           1
|           |
2 - 3 - 4 - 5
|   |   |   |
6   7   8   9

One optimal solution is to put beacons into cities 0 and 1.

3)
{"NYNYNNYNN",
 "YNYNYNNYN",
 "NYNNNYNNY",
 "YNNNNNNNN",
 "NYNNNNNNN",
 "NNYNNNNNN",
 "YNNNNNNNN",
 "NYNNNNNNN",
 "NNYNNNNNN"}

Returns: 3

The graph looks as follows:

3   4   5
|   |   |
0 - 1 - 2
|   |   |
6   7   8



4)
{"NYYYYYYYYY",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN"}


Returns: 8



5)
{"N"}

Returns: 0

We don't need any beacon at all, since there is only 1 city.

*/
// END CUT HERE
#line 165 "TPS.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;
typedef long long LL;


class TPS
{
        public:
		vector<string> mat;
		int dp[55][55][2];
		int n;

		int dfs(int now,int p,int st) {
			if(dp[now][p][st]>=0) 
				return dp[now][p][st];
			int sum=0,tmp=n,c=0,ret=n;
			for(int i=0; i<n; i++)
				if(i!=p&&mat[now][i]=='Y') {
					c++;
					sum+=dfs(i,now,1);
				}
			if(c==0) {
				return dp[now][p][st]=st;
			}
			for(int i=0; i<n; i++)
				if(i!=p&&mat[now][i]=='Y')
					tmp=min(tmp,sum-dfs(i,now,1)+dfs(i,now,0));
			ret=min(ret,1+tmp);
			if(p!=n) {
				if(c==1&&st==1)
					ret=min(ret,sum);
				else
					ret=min(ret,tmp);
			}
			return dp[now][p][st]=ret;
		}

        int minimalBeacons(vector <string> linked) {
			memset(dp,-1,sizeof(dp));
			mat=linked;
			n=linked.size();
			int ret=n;
			for(int i=0; i<n; i++) {
				ret=min(ret,dfs(i,n,0));
			}
			return ret;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNN",
 "YNYN",
 "NYNY",
 "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimalBeacons(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimalBeacons(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNYNNNNNNN",
 "NNNNNYNNNN",
 "YNNYNNYNNN",
 "NNYNYNNYNN",
 "NNNYNYNNYN",
 "NYNNYNNNNY",
 "NNYNNNNNNN",
 "NNNYNNNNNN",
 "NNNNYNNNNN",
 "NNNNNYNNNN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minimalBeacons(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNYNNYNN",
 "YNYNYNNYN",
 "NYNNNYNNY",
 "YNNNNNNNN",
 "NYNNNNNNN",
 "NNYNNNNNN",
 "YNNNNNNNN",
 "NYNNNNNNN",
 "NNYNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minimalBeacons(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYYYYYYYYY",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN",
 "YNNNNNNNNN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, minimalBeacons(Arg0)); }
	void test_case_5() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, minimalBeacons(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TPS ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
