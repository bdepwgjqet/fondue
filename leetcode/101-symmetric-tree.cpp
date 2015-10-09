#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    bool isSym(TreeNode* l, TreeNode* r) {
        if (l==NULL && r==NULL) {
            return true;
        }
        if (l==NULL) {
            return false;
        }
        if (r==NULL) {
            return false;
        }
        if (l->val != r->val) {
            return false;
        }
        return isSym(l->left,r->right) && isSym(l->right,r->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isSym(root,root);
    }
};

int main() {

    return 0;
}
