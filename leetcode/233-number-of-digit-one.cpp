#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    const static int N = 30;
    int dp[N][2];
    int dpn[N][2];
    vector<int> num;
    int dfs(int idx, int tag) {
        if (dp[idx][tag] != -1) {
            return dp[idx][tag];
        }
        if (idx == num.size()) {
            dpn[idx][tag] = 1;
            return dp[idx][tag] = 0;
        }
        int res = 0;
        int resn = 0;
        for (int d=0; d<10; d++) {
            int next_tag = tag;
            if (tag == 0) {
                if (d > num[idx]) {
                    continue;
                }
                if (d<num[idx]) {
                    next_tag = 1;
                }    
            } else {
                next_tag = 1;
            }
            int cur_dp = dfs(idx + 1, next_tag);
            if (d == 1) {
                cur_dp = cur_dp + dpn[idx+1][next_tag];
            }
            res = res + cur_dp;
            resn = resn + dpn[idx+1][next_tag];
        }
        dpn[idx][tag] = resn;
        return dp[idx][tag]=res;
    }

    int countDigitOne(int n) {
        num.clear();
        memset(dp, -1, sizeof(dp));
        memset(dpn, -1, sizeof(dpn));
        while (n) {
            int d = n%10;
            n = n/10;
            num.push_back(d);
        }
        reverse(num.begin(), num.end());
        return dfs(0, 0);
    }
};

int main() {
    Solution s;
    printf("%d\n", s.countDigitOne(13));
    return 0;
}

