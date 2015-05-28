#include <cstdio>

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 

class Solution {

public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        TreeLinkNode *now = root;
        TreeLinkNode *pre = NULL;
        TreeLinkNode *next = NULL;
        while (now != NULL) {
            if (now->left != NULL) {
                if (pre != NULL) {
                    pre->next = now->left;
                }
                if (next == NULL) {
                    next = now->left;
                }
                pre = now->left;
            }
            if (now->right != NULL) {
                if (pre != NULL) {
                    pre->next = now->right;
                }
                if (next == NULL) {
                    next = now->right;
                }
                pre = now->right;
            }
            now = now->next;
        }
        connect(next);
    }
};

int main () {
    Solution s;
    TreeLinkNode *root = NULL;
    s.connect(root);
    return 0;
}
