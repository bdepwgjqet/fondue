#include <cstdio>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> dfs(int l, int r) {
        vector<TreeNode*> ans;
        if (l > r) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i=l; i<=r; i++) {
            vector<TreeNode*> left = dfs(l,i-1);
            vector<TreeNode*> right = dfs(i+1,r);
            for(int u=0; u<left.size(); u++) {
                for(int v=0; v<right.size(); v++) {
                    TreeNode* now = new TreeNode(i);
                    now->left = left[u];
                    now->right = right[v];
                    ans.push_back(now);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
    }
};

int main() {
    return 0;
}
