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
        while (now != NULL) {
            if (now->left == NULL || now->right == NULL) {
                break;
            }
            now->left->next = now->right;
            if (now->next != NULL) {
                now->right->next = now->next->left;
            }
            now = now->next;
        }
        connect(root->left);
    }
};

int main () {
    Solution s;
    TreeLinkNode *root = NULL;
    s.connect(root);
    return 0;
}
