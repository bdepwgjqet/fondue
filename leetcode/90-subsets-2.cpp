#include <cstdio>
#include <map>
#include <vector>

using namespace std;

class Solution {

public:
    void dfs(int id, vector<int> &vec, map<int,int> &mp, vector<int> val, vector<vector<int> > &ans) {
        if (id == vec.size()) {
            ans.push_back(val);
            return;
        }
        for(int i=0; i<=mp[vec[id]]; i++) {
            if (i > 0) {
                val.push_back(vec[id]);
            }
            dfs(id+1,vec,mp,val,ans);
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        map<int,int> mp;
        vector<int> vec;
        for (int i=0; i<nums.size(); i++) {
            if (mp.count(nums[i])) {
                mp[nums[i]]++;
            } else {
                mp[nums[i]]=1;
            }
        }
        for (map<int,int>::iterator it=mp.begin(); it!=mp.end(); it++) {
            vec.push_back(it->first);
        }
        vector<vector<int> > ans;
        vector<int> val;
        dfs(0,vec,mp,val,ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v;
    v.push_back(0);
    vector<vector<int> > ans = s.subsetsWithDup(v);
    for (int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
    return 0;
}
