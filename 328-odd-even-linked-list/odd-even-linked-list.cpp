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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head -> next){
            return head;
        }

        ListNode *even = head -> next;
        ListNode *odd = head;
        ListNode *temp = head;
        ListNode *evenh = even;
        int c = 0;

        while(odd && even && even -> next && odd -> next){
            if(c == 0){
                temp = even;
                odd -> next = even -> next;
                odd = temp -> next;
                c++;
            }
            if(c == 1){
                temp = odd;
                even -> next = odd -> next;
                even = temp -> next;
                c--;
            }
        }

        if (odd) odd->next = evenh;
        if (even) even->next = NULL;

        return head;
    }
};