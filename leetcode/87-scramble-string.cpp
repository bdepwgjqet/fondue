#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

class Solution {
    const static int N = 51;
    int dp[N][N][N];
    string ss1,ss2;

public:
    int dfs(int l1,int l2,int l) {
        if (dp[l1][l2][l] >= 0) {
            return dp[l1][l2][l];
        }
        if (l <= 1) {
            return dp[l1][l2][l]=(ss1[l1]==ss2[l2]);
        }
        int ret = 0;
        for (int i=1; i<l; i++) {
            if (dfs(l1,l2,i) && dfs(l1+i,l2+i,l-i)) {
                ret = 1;
            }
            if (dfs(l1,l2+l-i,i) && dfs(l1+i,l2,l-i)) {
                ret = 1;
            }
        }
        return dp[l1][l2][l] = ret;
    }
    bool isScramble(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        int l1 = s1.length();
        int l2 = s2.length();
        ss1 = s1;
        ss2 = s2;
        if(l1 != l2) {
            return false;
        }
        if (l1 == 1) {
            return (s1[0] == s2[0]);
        }
        for(int i=1; i<l1; i++) {
            if (dfs(0,0,i) && dfs(i,i,l1-i)) {
                return true;
            }
            if (dfs(0,l1-i,i) && dfs(i,0,l1-i)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    //printf("%d\n",s.isScramble("abcefg","efgabc"));
    printf("%d\n",s.isScramble("a","a"));
    return 0;
}
