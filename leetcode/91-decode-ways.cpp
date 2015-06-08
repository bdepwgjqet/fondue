#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {

    vector<int> dp[27];

public:
    int dfs(int id, int v, string &s) {
        if (v > 26) {
            return 0;
        }
        if (s[id] == '0' && v==0) {
            return dp[v][id] = 0;
        }
        if (dp[v][id] >= 0) {
            return dp[v][id];
        }
        if (id == s.length()) {
            if (1<=v && v<=26) {
                return dp[v][id] = 1;
            } else {
                return dp[v][id] = 0;
            }
        }
        int ans = 0;
        int now = v*10+(s[id]-'0');
        ans += dfs(id+1,now,s);
        if (1<=now && now<=26) {
            ans += dfs(id+1,0,s);
        }
        return dp[v][id]=ans;
    }

    int numDecodings(string s) {
        for(int i=0; i<=s.length(); i++) {
            for(int j=0; j<27; j++) {
                dp[j].push_back(-1);
            }
        }
        return dfs(0,0,s);
    }
};

int main() {
    Solution s;
    printf("%d\n",s.numDecodings("1"));
    return 0;
}
