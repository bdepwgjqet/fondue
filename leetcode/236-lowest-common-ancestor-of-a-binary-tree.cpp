#include <cstdio>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return root;
        }
        if (root == p || root == q) {
            return root;
        }
        TreeNode *l1 = lowestCommonAncestor(root->left, p, q); 
        TreeNode *l2 = lowestCommonAncestor(root->right, p, q); 
        if (l1 != NULL && l2 != NULL) {
            return root;
        }
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if (l1 != NULL) {
            return l1;
        }
        return l2;
    }
};

int main() {
    return 0;
}
