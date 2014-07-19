/*
* temp.cpp
*
* Created on: 2012-7-18
* Author: BSBandme
*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <list>
#include <iomanip>
#include <math.h>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <sstream>

using namespace std;

#define mpr make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}
template <class T> inline T max1(T a, T b, T c = -1234567, T d = -1234567) {
T ans = a > b ? a : b;
if(c != -1234567) ans = max1(ans, c);
if(d != -1234567) ans = max1(ans, d);
return ans;
}
template <class T> inline T min1(T a, T b, T c = -1234567, T d = -1234567) {
T ans = a < b ? a : b;
if(c != -1234567) ans = min(ans, c);
if(d != -1234567) ans = min(ans, d);
return ans;
}
template <class T> inline T gcd1(T a, T b) {
if(a < b) swap(a, b);
if(a % b == 0) return b;
return gcd1(b, a % b);
}
template <class T> inline T lb(T num) {return num & (-num); }
inline int jud(double a, double b){
if(abs(a) < eps && abs(b) < eps) return 0;
else if(abs1(a - b) / abs1(a) < eps) return 0;
if(a < b) return -1;
return 1;
}
template <typename t>
inline int jud(t a, t b){
if(a < b) return -1;
if(a == b) return 0;
return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
int be = 0, en = na - 1;
if(*a <= *(a + na - 1)){
if(f_lb == 0) while(be < en){
int mid = (be + en + 1) / 2;
if(jud(*(a + mid), val) != 1) be = mid;
else en = mid - 1;
}else while(be < en){
int mid = (be + en) / 2;
if(jud(*(a + mid), val) != -1) en = mid;
else be = mid + 1;
}
if(f_small && jud(*(a + be), val) == 1) be--;
if(!f_small && jud(*(a + be), val) == -1) be++;
} else {
if(f_lb) while(be < en){
int mid = (be + en + 1) / 2;
if(jud(*(a + mid), val) != -1) be = mid;
else en = mid - 1;
}else while(be < en){
int mid = (be + en) / 2;
if(jud(*(a + mid), val) != 1) en = mid;
else be = mid + 1;
}
if(!f_small && jud(*(a + be), val) == -1) be--;
if(f_small && jud(*(a + be), val) == 1) be++;
}
return be;
}
inline int bitnum(ull nValue){
nValue = ((0xaaaaaaaaaaaaaaaaull & nValue)>>1) + (0x5555555555555555ull & nValue);
nValue = ((0xccccccccccccccccull & nValue)>>2) + (0x3333333333333333ull & nValue);
nValue = ((0xf0f0f0f0f0f0f0f0ull & nValue)>>4) + (0x0f0f0f0f0f0f0f0full & nValue);
nValue = ((0xff00ff00ff00ff00ull & nValue)>>8) + (0x00ff00ff00ff00ffull & nValue);
nValue = ((0xffff0000ffff0000ull & nValue)>>16) + (0x0000ffff0000ffffull & nValue);
nValue = ((0xffffffff00000000ull & nValue)>>32) + (0x00000000ffffffffull & nValue);
return nValue;
}
long long pow(long long n, long long m, long long mod = 0){
long long ans = 1;
long long k = n;
while(m){
if(m & 1) {
ans *= k;
if(mod) ans %= mod;
}
k *= k;
if(mod) k %= mod;
m >>= 1;
}
return ans;
}


//.........................mi.......feng.......xian.......wai.......jin.......zhi.......challenge...............................................

ll n, m;
int ncase;

int main(){
ios_base::sync_with_stdio(0);
//	freopen("input.txt", "r", stdin);
scanf("%d", &ncase);
while(scanf("%I64d%I64d", &n, &m) != -1) {
ll a = m, b = pow(n, m - 1);
ll gcd = __gcd(a, b);
a /= gcd; b /= gcd;
printf("%I64d/%I64d\n", a, b);
}

return 0;
}

