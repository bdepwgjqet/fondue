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
    void dfs(TreeNode *root, vector<int> &ans) {
        if (root == NULL) {
            return;
        }
        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};


int main() {
    return 0;
}
