#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

public:

    void dfs(int id, int dot, string now, string s, vector<string> &ans) {
        if (dot == 4) {
            if (id == s.length()) {
                ans.push_back(now);
            }
            return;
        }
        if (id >= s.length()) {
            return;
        }
        int val = 0;
        for (int i=id; i<s.length(); i++) {
            if (i > id && val == 0) {
                break;
            }
            val *= 10;
            val += s[i]-'0';
            if (val > 255) {
                break;
            }
            string next;
            if (dot > 0) {
                next = now+"."+s.substr(id,i-id+1);
            } else {
                next = s.substr(id,i-id+1);
            }
            dfs(i+1, dot+1, next, s, ans);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(0,0,"", s,ans);
        return ans;
    }
};

int main() {
    Solution s;
    //vector<string> ans = s.restoreIpAddresses("25525511135");
    vector<string> ans = s.restoreIpAddresses("010010");
    for (int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    puts("");
    return 0;
}
