#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {

vector<vector<string> > dp;
vector<int> vis;
string ss;
unordered_set<string>& dic;

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) { 
        dp.resize(dict.size()+1);
        vis.resize(dict.size()+1);
        for (int i=0; i<dict.size()+1; i++) {
            vis[i]=-1;
        }
        string nows = "";
        dic = dict;
        dfs(0,nows);    
        return dp[0];
    }

    bool dfs(int now, string nows) {
        if (vis[now] >= 0) {
            return vis[now];
        }
        string tmp = "";
        vector<string> idp;
        for (int i=now; i < ss.length(); i++) {
            tmp += ss[i];
            if (dic.count(tmp) > 0) {
                if (nows.length() > 0) {
                    dfs(i+1, nows+" "+tmp);
                } else {
                    dfs(i+1, nows+tmp);
                }
                for(int j=0; j<dp[i+1].size(); j++) {
                    idp.push_back(tmp+dp[i+1][j]);
                }
            }	    
        }
        dp[now]=idp;
        return vis[now] = 1;
    }
};

int main() {
    return 0;
}
