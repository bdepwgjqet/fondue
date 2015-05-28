#include <cstdio>
#include <algorithm>

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

    TreeNode *pre = NULL;
    TreeNode *fir = NULL;
    TreeNode *sec = NULL;

public:
    void dfs(TreeNode *now) {
        if (now->left != NULL) {
            dfs(now->left);
        }
        if (pre != NULL && now->val < pre->val) {
            if (fir == NULL) {
                fir = pre;
                sec = now;
            } else {
                sec = now;
            }
        }
        pre = now;
        if (now->right != NULL) {
            dfs(now->right);
        }
    }

    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(fir->val,sec->val);
    }
};

int main() {
    return 0;
}
