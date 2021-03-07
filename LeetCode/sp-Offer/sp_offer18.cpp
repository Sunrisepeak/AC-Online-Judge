/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) return head;
        if (head->val == val) return head->next;
        ListNode *p = head;
        while (p->next != nullptr && p->next->val != val) p = p->next;
        if (p->next != nullptr) {
            auto q = p->next;
            p->next = q->next;
            delete q;
        }
        return head;
    }
};
