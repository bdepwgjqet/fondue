#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, mx = 0, len = s.length();
        int cnt[26];
        int ans = 0;
        memset(cnt,0,sizeof(cnt));
        for(; r<len;) {
            mx = max(mx, ++cnt[s[r]-'A']);
            r++;
            if (r-l-mx > k) {
                cnt[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};

int main() {
    Solution s;
    //printf("%d", s.characterReplacement("ABAB",2));
    printf("%d", s.characterReplacement("AABABBA",1));
}
