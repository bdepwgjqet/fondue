// BEGIN CUT HERE

// END CUT HERE
#line 5 "TopView.cpp"
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

int mat[N][N];
int vis[N],in[N],tag[N];
int mp[N][N];
vector<int> ele;
string ret;

int cmp(int a,int b){ return a<b; }

class TopView
{
        public:
		int toposort()
		{
			int cnt=0,ttl=ele.size(),i,now;
			memset(tag,0,sizeof(tag));
			for(; cnt<ttl; )
			{
				for(i=0; i<ttl; i++)
					if(!tag[i]&&in[ele[i]]==0)
						break;
				if(i>=ttl) return 0;
				now=i;
				tag[now]=1;
				ret.push_back(ele[now]+'0');
				cnt++;
				for(i=0; i<ttl; i++)
					if(mp[ele[now]][ele[i]]&&!tag[i])
						in[ele[i]]--;
			}
			return 1;
		}

        string findOrder(vector <string> grid)
        {
			int m=grid.size(),n=grid[0].length();
			memset(vis,0,sizeof(vis));
			memset(mp,0,sizeof(mp));
			memset(in,0,sizeof(in));
			ele.clear();
			ret.clear();
			for(int i=0; i<m; i++)
				for(int j=0; j<n; j++)
				{
					if(grid[i][j]=='.')
					{
						mat[i][j]=-1;
						continue;
					}
					if(!vis[grid[i][j]])
					{
						mat[i][j]=grid[i][j]-'0';
						vis[grid[i][j]]=1;
						ele.push_back(mat[i][j]);
					}
					else
						mat[i][j]=grid[i][j]-'0';
				}
			sort(ele.begin(),ele.end(),cmp);
			for(int k=0; k<ele.size(); k++)
			{
				int mxx=-1,mix=N,mxy=-1,miy=N;
				for(int i=0; i<m; i++)
					for(int j=0; j<n; j++)
						if(mat[i][j]==ele[k])
						{
							mxx=max(mxx,i);
							mix=min(mix,i);
							mxy=max(mxy,j);
							miy=min(miy,j);
						}
				for(int i=mix; i<=mxx; i++)
					for(int j=miy; j<=mxy; j++)
					{
						if(mat[i][j]<0)
						{
							in[ele[k]]=inf;
						}
						else if(mat[i][j]!=ele[k])
						{
							mp[ele[k]][mat[i][j]]=1;
						}
					}
				for(int i=0; i<ele.size(); i++)
					if(mp[ele[k]][ele[i]])
						in[ele[i]]++;
			}
			if(toposort())
				return ret;
			else
				return "ERROR!";
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3();
	if ((Case == -1) || (Case == 4)) test_case_4();
	}

	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..AA..",
 ".CAAC.",
 ".CAAC."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CA"; verify_case(0, Arg1, findOrder(Arg0)); }
	void test_case_1() { string Arr0[] = {"..47..",
 "..74.."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ERROR!"; verify_case(1, Arg1, findOrder(Arg0)); }
	void test_case_2() { string Arr0[] = {"bbb666",
 ".655X5",
 "a65AA5",
 "a65AA5",
 "a65555"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "65AXab"; verify_case(2, Arg1, findOrder(Arg0)); }
	void test_case_3() { string Arr0[] = {"aabbaaaaaaaaaaaaaaaaaa",
 "aabbccccccccccccccaaaa",
 "aab11111ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ccccccccccaaaa",
 "aab12221ddddddddddaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aab13331DDDDDDDDDDaaaa",
 "aa.11111DDDDDDDDDDaaaa",
 "aaaaaaaaaaaaaaaaaaaaaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ERROR!"; verify_case(3, Arg1, findOrder(Arg0)); }
void test_case_4(){ string Arr0[]={"aabbaaaaaaaaaaaaaaaaaa", "aabbccccccccccccccaaaa", "aab11111ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ccccccccccaaaa", "aab12221ddddddddddaaaa", "aab13331DDDDDDDDDDaaaa", "aab13331DDDDDDDDDDaaaa", "aa.11111DDDDDDDDDDaaaa", "aaaaaaaaaaaaaaaaaaaaaa"};
vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ERROR!"; verify_case(4, Arg1, findOrder(Arg0)); 
}
// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        TopView ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
