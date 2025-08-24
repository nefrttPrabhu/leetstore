class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tt = l2;  
        ListNode* temp = l2;
        ListNode* prev = NULL;  
        int carry = 0;

        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            if (temp) {
                temp->val = sum % 10;
                carry = sum / 10;
                prev = temp;
                temp = temp->next;
            } else {
                prev->next = new ListNode(sum % 10);
                prev = prev->next;
                carry = sum / 10;
            }
        }

        if (carry) {
            prev->next = new ListNode(carry);
        }

        return tt;
    }
};
