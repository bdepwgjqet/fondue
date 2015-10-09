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

    void dfs(TreeNode* now, vector<vector<int> > &ans, int level) {
        if (now == NULL) {
            return;
        }
        if (ans.size() <= level) {
            ans.push_back(*(new vector<int>()));
        }
        ans[level].push_back(now->val);
        dfs(now->left,ans,level+1);
        dfs(now->right,ans,level+1);
    }

    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        dfs(root,ans,0);
        return ans;
    }
};

int main() {
    return 0;
}
