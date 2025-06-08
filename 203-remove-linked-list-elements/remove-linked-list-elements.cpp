class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        if (!head) return NULL;

        ListNode* prev = head;
        ListNode* temp = head->next;

        while (temp != NULL) {
            if (temp->val == val) {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};
