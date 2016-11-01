#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<int> stk;
        bool first = true;
        for (int i=0; i<preorder.length(); i++) {

            /*
            printf("%d =>", i);
            for(int j=0; j<stk.size(); j++) {
                printf("%d ",stk[j]);
            }
            puts("");
            */

            if (preorder[i]=='#') {
                if (first) {
                    first = false;
                    continue;
                } else {
                    if (stk.size() <= 0) {
                        return false;
                    }
                    int now = stk[stk.size()-1];
                    if (now == 1) {
                        stk.pop_back();
                    } else if (now == 2) {
                        stk.pop_back();
                        stk.push_back(1);
                    } else {
                        //impossible
                        return false;
                    }
                }
            } else if (preorder[i]==',') {
                continue;
            } else {

                if (first) {
                    stk.push_back(2);
                } else {
                    if (stk.size() <= 0) {
                        return false;
                    }

                    int now = stk[stk.size()-1];
                    if (now == 1) {
                        stk.pop_back();
                    } else if (now == 2) {
                        stk.pop_back();
                        stk.push_back(1);
                    } else {
                        //impossible
                        return false;
                    }
                    stk.push_back(2);
                }
                for(;preorder[i]!=',' && i<preorder.length(); i++);
            }
            first = false;
        }
        if (stk.size() == 0) {
            return true;
        }
        return false;
    } 
};

int main () {
    Solution s;
    //bool ans = s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
    //bool ans = s.isValidSerialization("1,#");
    //bool ans = s.isValidSerialization("9,#,#,1");
    //bool ans = s.isValidSerialization("91,13,14,#,#,10");
    bool ans = s.isValidSerialization("#");
    if (ans) {
        printf("%d\n",1);
    } else {
        printf("%d\n",0);
    }
    return 0;
}
