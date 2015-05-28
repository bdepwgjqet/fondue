#include <cstdio>
#include <algorithm>
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
    vector<int> maxLink;

    const static int inf = 0x3fffffff;

public:
    int maxPathSum(TreeNode* root) {
        int maxl = 0;
        int maxr = 0;
        int maxs = -inf;
        if (root->left != NULL) {
            maxs = max(maxs,maxPathSum(root->left));
            maxl = maxLink[maxLink.size()-1];
        }
        if (root->right != NULL) {
            maxs = max(maxs,maxPathSum(root->right));
            maxr = maxLink[maxLink.size()-1];
        }
        maxLink.push_back(max(root->val,max(maxl+root->val,maxr+root->val)));
        return max(max(max(max(maxs,maxl+maxr+root->val),maxl+root->val),maxr+root->val),root->val);
    }
};

int main() {
    return 0;
}
