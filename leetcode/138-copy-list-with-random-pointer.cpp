#include <cstdio>

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        RandomListNode *tmp; 
        tmp = head;
        while(tmp != NULL) {
            RandomListNode *add = new RandomListNode(tmp->label);
            add->next = tmp->next;
            tmp->next = add;
            tmp = add->next;
        }
        tmp = head;
        while (tmp != NULL) {
            if (tmp->random != NULL) {
                tmp->next->random = tmp->random->next;
            } else {
                tmp->next->random = NULL;
            }
            tmp = tmp->next->next;
        }
        RandomListNode *ans = head->next;
        RandomListNode *ori = head;
        tmp = ans;
        while (tmp != NULL) {
            ori->next = tmp->next;
            if (tmp->next != NULL) {
                tmp->next = tmp->next->next;
            }
            ori = ori->next;
            tmp = tmp->next;
        }
        return ans;        
    }
};

int main() {
    Solution s;
    RandomListNode *head = new RandomListNode(-1);
    RandomListNode *ans = s.copyRandomList(head);
    while(ans != NULL) {
        printf ("%d ",ans->label);
        ans = ans -> next;
    }
    puts("");
    return 0;
}

