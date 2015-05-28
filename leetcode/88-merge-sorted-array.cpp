#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int po = m + n - 1;
        for (int i=m-1; i>=0; i--) {
            nums1[po] = nums1[i];
            po = po - 1;
        }
        int p1=n,p2=0,now = 0;
        while(p1 < m+n || p2 < n) {
            if (p1 >= m+n) {
                nums1[now++] = nums2[p2++];
                continue;
            }
            if (p2 >= n) {
                nums1[now++] = nums1[p1++];
                continue;
            }
            if (nums1[p1] < nums2[p2]) {
                nums1[now++] = nums1[p1++];
            } else {
                nums1[now++] = nums2[p2++];
            }
        }
    }
};

int main() {
    Solution s;
    return 0;
}
