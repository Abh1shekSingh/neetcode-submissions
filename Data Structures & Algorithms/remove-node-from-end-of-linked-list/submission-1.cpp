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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;

        while(temp) {
            size++;
            temp = temp->next;
        }

        int t = size - n + 1;

        ListNode* target = head;

        while(t > 1) {
            target = target->next;
            t--;
        }

        temp = head;
        if(temp == target) return temp->next;
        while(temp->next != target) {
            temp = temp->next;
        }

        temp->next = target->next;
        target->next = NULL;
        delete(target);



       return head;
    }
};
