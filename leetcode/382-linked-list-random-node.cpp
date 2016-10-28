#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode *head;

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *cur = head->next;
        ListNode *ans = head;
        int now = 2;
        while(cur) {
            int rd = rand()%now;
            if (rd==0) {
                ans = cur;
            }
            cur=cur->next;
            now++;
        }
        return ans->val;
    }
};

int main() {
    ListNode *hd = new ListNode(1);
    hd->next = new ListNode(2);
    hd->next->next = new ListNode(3);
    Solution s = Solution(hd);
    printf("%d\n",s.getRandom());
    return 0;
}
