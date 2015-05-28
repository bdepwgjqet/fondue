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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);
        ListNode *tmp = head;
        ListNode *ltmp = left;
        ListNode *rtmp = right;
        while(tmp != NULL) {
            if (tmp->val < x) {
                ltmp->next = tmp;
                ltmp = ltmp->next;
            } else {
                rtmp->next = tmp;
                rtmp = rtmp->next;
            }
            tmp = tmp->next;
        }
        rtmp->next = NULL;
        ltmp->next = right->next;
        return left->next;
    }
};

int main() {
    return 0;
}
