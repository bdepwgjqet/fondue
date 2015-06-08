#include <cstdio>
#include <algorithm>
#include <utility>

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
    pair<int,int> dfs(TreeNode* root, bool &ans) {
        int mx=root->val,mi=root->val;
        if (root->left != NULL) {
            pair<int,int> left = dfs(root->left, ans);
            mx = max(left.first,mx);
            mi = min(left.second,mi);
            if (left.first >= root->val) {
                ans = false;
            }
        }
        if (root->right != NULL) {
            pair<int,int> right = dfs(root->right,ans);
            mx = max(right.first,mx);
            mi = min(right.second,mi);
            if(right.second <= root->val) {
                ans = false;
            }
        }
        return make_pair(mx,mi);
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        bool ans = true;
        dfs(root,ans);
        return ans;
    }
};

int main() {
    return 0;
}
