#line 159 "FoxAndFencing.cpp"
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

class FoxAndFencing
{
        public:
        string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d)
        {
			if(mov1+rng1>=d) return string("Ciel");
			if(mov1+rng1>mov2+rng2) {
				if(mov1<=mov2) return string("Draw");
				else {
					if(mov2+rng2+1+mov2<=mov1+rng1)
						return string("Ciel");
					else
						return string("Draw");
				}
			} else if(mov1+rng1==mov2+rng2) {
				return string("Draw");
			} else {
				if(mov1==mov2) {
					if(mov2+rng2>=mov1+d)
						return string("Liss");
					else 
						return string("Draw");
				}
				else if(mov1>mov2) {
					if(mov2+rng2>=mov1+d)
						return string("Liss");
					else return string("Draw");
				}
				else {
					if(mov2+rng2>=mov1+d)
						return string("Liss");
					if(mov2+rng2>=mov1+rng1+1+mov1)
						return string("Liss");
					return string("Draw");
				}
			}
        }
        

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
