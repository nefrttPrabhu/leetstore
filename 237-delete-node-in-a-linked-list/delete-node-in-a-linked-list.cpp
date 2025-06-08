class Solution {
public:
    void deleteNode(ListNode* temp) {
        temp->val=temp->next->val;
        temp->next=temp->next->next;
    }
};