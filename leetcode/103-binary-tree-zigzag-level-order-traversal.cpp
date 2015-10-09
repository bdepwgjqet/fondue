#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void dfs(TreeNode* root, vector<vector<int> > &ans, int level) {
        if (root == NULL) {
            return;
        }
        if (level >= ans.size()) {
            ans.push_back(*(new vector<int>));
        }
        ans[level].push_back(root->val);
        dfs(root->left, ans, level+1);
        dfs(root->right, ans, level+1);
    }

    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        dfs(root,ans,0);
        for (int i=0; i<ans.size(); i++) {
            if (i&1) {
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
