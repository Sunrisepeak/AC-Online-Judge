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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *ans = p2;
        int carry = 0;
        int sum;
        while(p2 != NULL && p1 != NULL)
        {
            //calculate
            sum = p2->val + p1->val + carry;
            p2->val = sum % 10;
            carry = sum / 10;
            //add node
            if(p1->next == NULL && p2->next != NULL)
                p1->next = add_node(0);
            else if(p2->next == NULL && p1->next != NULL)
                p2->next = add_node(0);
            //judgement 
            if(p2->next == NULL && p1->next == NULL && carry != 0)
                p2->next = add_node(carry);
            //move to next node
            p1 = p1->next;
            p2 = p2->next;
        }    
        return ans;
    }
    
private:
    //add a node
    ListNode* add_node(int v)
    {
        ListNode* s = (ListNode* )malloc(sizeof(ListNode));
        s->val = v;
        s->next = NULL;
        return s;
    }

};