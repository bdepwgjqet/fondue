#include <cstdio>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *odd=head;
        ListNode *hodd = head;
        ListNode *even=head->next;
        ListNode *heven=head->next;

        head = head->next->next;

        while(head) {
            odd->next = head;
            even->next = head->next;
            odd = odd->next;
            even = even->next;

            if (head->next) {
                head = head->next->next;
            } else {
                break;
            }
        }
        odd->next = heven;
        return hodd;
    }
};

int main() {
    ListNode *hd = new ListNode(1);
    hd->next = new ListNode(2);
    hd->next->next = new ListNode(3);
    hd->next->next->next = new ListNode(4);
    Solution s;
    ListNode *ans = s.oddEvenList(hd);
    while(ans) {
        printf("%d - ", ans->val);
        ans = ans->next;
    }
    return 0;
}
