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
    vector<int> reversePrint(ListNode* head) {
        int len = 0;
        auto p = head;
        while (p != nullptr) {
            len++;
            p = p->next;
        }
        vector<int> arr(len);
        p = head;
        for (auto rit = arr.rbegin(); rit != arr.rend(); rit++, p = p->next) {
            *rit = p->val;
        }
        return arr;
    }
};
