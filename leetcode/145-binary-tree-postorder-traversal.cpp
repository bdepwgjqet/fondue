#include <cstdio>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> tag;
        vector<int> ans;
        stack.push_back(root);
        tag.push_back(0);
        while(stack.size() > 0) {
            TreeNode *now = stack.back();
            int flag = tag.back();
            stack.pop_back();
            tag.pop_back();
            if (flag) {
                ans.push_back(now->val);
                continue;
            }
            if (now == NULL) {
                continue;
            }
            stack.push_back(now);
            stack.push_back(now->right);
            stack.push_back(now->left);
            tag.push_back(1);
            tag.push_back(0);
            tag.push_back(0);
        }
        return ans;
    }
};

int main() {
    return 0;
}
