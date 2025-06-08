/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;

        while (t1 && t2) {
            int sum = t1->val + t2->val + carry;
            ListNode* nn = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = nn;
            temp = nn;
            t1 = t1->next;
            t2 = t2->next;
        }

        while (t1) {
            int sum = t1->val + carry;
            ListNode* nn = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = nn;
            temp = nn;
            t1 = t1->next;
        }

        while (t2) {
            int sum = t2->val + carry;
            ListNode* nn = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = nn;
            temp = nn;
            t2 = t2->next;
        }

        if (carry) {
            temp->next = new ListNode(carry);
        }

        return dummy->next;
    }
};
