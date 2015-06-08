#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string fs = s+"#"+rev;
        vector<int> f(fs.length(),0);
        f[0] = -1;
        for (int i=1; i<fs.length(); i++) {
            int p = f[i-1];
            while(p>=0 && fs[p+1] != fs[i]) {
                p = f[p];
            }
            if (fs[p+1] == fs[i]) {
                f[i] = p+1;
            } else {
                f[i] = -1;
            }
        }
        int ans = f[fs.length()-1];
        return rev.substr(0,s.length()-ans-1)+s;
    }
};

int main() {
    Solution s;
    cout<<s.shortestPalindrome("abbacd")<<endl;
    return 0;
}
