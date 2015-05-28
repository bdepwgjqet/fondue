#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

class Solution {

    string ss1,ss2,ss3;
    const static int N = 1001;
    int dp[N][N];
public:

    int dfs(int ga,int gb) {
        if (dp[ga][gb] >= 0) {
            return dp[ga][gb];
        }
        if (ga == ss1.length() && gb == ss2.length()) {
            return dp[ga][gb] = (ga+gb == ss3.length());
        }
        int ret = 0;
        if (ga < ss1.length() && ss1[ga] == ss3[ga+gb]) {
            ret = ret | dfs(ga+1,gb);
        }
        if (gb < ss2.length() && ss2[gb] == ss3[ga+gb]) {
            ret = ret | dfs(ga,gb+1);
        }
        return dp[ga][gb] = ret;
    }

    bool isInterleave(string s1, string s2, string s3) {
        ss1 = s1;
        ss2 = s2;
        ss3 = s3;
        memset(dp,-1,sizeof(dp));
        if(dfs(0,0)) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    //printf("%d\n",s.isInterleave("aabcc","dbbca","aadbbbaccc"));
    printf("%d\n",s.isInterleave("aabcc","dbbca","aadbbcbcac"));
    return 0;
}
