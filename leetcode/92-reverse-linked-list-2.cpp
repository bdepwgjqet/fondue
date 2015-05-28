#include <cstdio>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *first = head;
        ListNode *ans = new ListNode(0);
        ListNode *pre = ans;
        ans->next = head;
        for (int i=1; i<m; i++) {
            first = first->next;
            pre = pre->next;
        }
        ListNode *next = first->next;
        ListNode *end = first;
        for (int i=0; i<n-m; i++) {
            ListNode *tmp = next->next;
            next->next = first;
            first = next;
            next = tmp;
        }
        end->next = next;
        pre->next = first;
        return ans->next;
    }
};

int main() {
    return 0;
}
