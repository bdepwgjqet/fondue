#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) {
            return 1;
        }
        vector<int> dp;
        for (int i=0; i<=n; i++) {
            dp.push_back(0);
        }
        dp[0] = dp[1] = 1;
        for (int i=2; i<=n; i++) {
            for (int j=0; j<i; j++) {
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};

int main() {
    return 0;
}
