// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel has some items. The weight of the i-th (0-based) item is item[i]. She wants to put all items into bins.


The capacity of each bin is 300. She can put an arbitrary number of items into a single bin, but the total weight of items in a bin must be less than or equal to 300.


You are given the vector <int> item. It is known that the weight of each item is between 100 and 300, inclusive. Return the minimal number of bins required to store all items.


DEFINITION
Class:BinPacking
Method:minBins
Parameters:vector <int>
Returns:int
Method signature:int minBins(vector <int> item)


CONSTRAINTS
-item will contain between 1 and 50 elements, inclusive.
-Each element of item will be between 100 and 300, inclusive.


EXAMPLES

0)
{150, 150, 150, 150, 150}

Returns: 3

You have five items and each bin can hold at most two of them. You need at least three bins.

1)
{130, 140, 150, 160}

Returns: 2

For example, you can distribute the items in the following way:

Bin 1: 130, 150
Bin 2: 140, 160



2)
{100, 100, 100, 100, 100, 100, 100, 100, 100}

Returns: 3



3)
{100, 200, 100, 100, 100, 100, 200, 100, 200}

Returns: 4



4)
{157, 142, 167, 133, 135, 157, 143, 160, 141, 123, 162, 159, 165, 137, 138, 152}

Returns: 8



*/
// END CUT HERE
#line 71 "BinPacking.cpp"
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

int tag[1000];

class BinPacking
{
        public:
        int minBins(vector <int> item)
        {
			int ret=0,two=0,one=0;
			vector<int> vec;
			for(int i=item.size()-1; i>=0; i--) {
				if(item[i]>200) {
					ret++;
				} else if(item[i]==100) {
					one++;
				} else if(item[i]==200) {
					two++;
				} else {
					vec.push_back(item[i]);
				}
			}
			ret+=two;
			one-=two;
			if(one<0) one=0;
			for(int i=0; i<one; i++)
				vec.push_back(100);
			sort(vec.begin(),vec.end());
			memset(tag,0,sizeof(tag));
			for(int i=vec.size()-1; i>=0; i--) {
				if(vec[i]==100) break;
				if(tag[i]) continue;
				int nowj=-1;
				for(int j=i-1; j>=0; j--) {
					if(tag[j]) continue;
					if(vec[i]+vec[j]<=300) {
						nowj=j;
						break;
					}
				}
				if(nowj==-1) {
					tag[i]=1;
					ret++;
				} else {
					tag[i]=tag[nowj]=1;
					ret++;
				}
			}
			one=0;
			for(int i=0; i<vec.size(); i++)
				if(!tag[i])
					one++;
			if(one%3)
				ret++;
			return ret+one/3;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {150, 150, 150, 150, 150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minBins(Arg0)); }
	void test_case_1() { int Arr0[] = {130, 140, 150, 160}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minBins(Arg0)); }
	void test_case_2() { int Arr0[] = {100, 100, 100, 100, 100, 100, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, minBins(Arg0)); }
	void test_case_3() { int Arr0[] = {100, 200, 100, 100, 100, 100, 200, 100, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minBins(Arg0)); }
	void test_case_4() { int Arr0[] = {157, 142, 167, 133, 135, 157, 143, 160, 141, 123, 162, 159, 165, 137, 138, 152}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, minBins(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        BinPacking ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
