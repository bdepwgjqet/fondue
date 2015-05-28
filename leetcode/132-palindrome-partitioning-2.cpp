#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
    
    vector<int> dp;
    vector<vector<int> > isp;
    string ss;
    const static int inf = 0x3ffffff;
    
public:
    int dfs(int now) {
        if(dp[now] >= 0) {
            return dp[now];
        }
        if (now == ss.length()) {
            return dp[now] = 0;
        }
        int ans = inf;
        for (int i=now; i<ss.length(); i++) {
            if (isp[now][i]>0) {
                if (i == ss.length() - 1) {
                    ans = min(ans,0);
                } else {
                    ans = min(ans,dfs(i+1)+1);
                }
            } 
        }
        return dp[now] = ans;
    }
    
    int minCut(string s) {
        dp.resize(s.length()+1);
        isp.resize(s.length()+1);
        ss = s;
        for(int i=0; i<s.length()+1; i++) {
            dp[i] = -1;
            isp[i].resize(s.length()+1);
            for (int j=0; j<s.length()+1; j++) {
                isp[i][j] = 0;
            }
        }
        for (int i=0; i<s.length(); i++) {
            isp[i][i] = 1;
            for (int j=1; i-j>=0 && i+j<s.length(); j++) {
                if (s[i-j] == s[i+j]) {
                    isp[i-j][i+j] = 1;
                    isp[i+j][i-j] = 1;
                } else {
                    break;
                }
            }
            for (int j=0; i-j>=0 && i+j+1<s.length(); j++) {
                if (s[i-j] == s[i+j+1]) {
                    isp[i-j][i+j+1] = 1;
                    isp[i+j+1][i-j] = 1;
                } else {
                    break;
                }
            }
        }
        return dfs(0);
    }
};

int main() {
    Solution s;
    printf("%d\n",s.minCut("ab"));
    printf("%d\n",s.minCut("bb"));
    return 0;
}
