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
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if(!head1 && !head2) return nullptr;
        if(!head1) return head2;
        if(!head2) return head1;
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        while(head1 && head2) {
            if(head1->val < head2->val) {
                dummy->next = new ListNode(head1->val);
                dummy = dummy->next;
                head1 = head1->next;
            }else {
                dummy->next = new ListNode(head2->val);
                dummy = dummy->next;
                head2 = head2->next;
            }
        }
        while(head1) {
            dummy->next = new ListNode(head1->val);
            dummy = dummy->next;
            head1 = head1->next;
        }
        while(head2) {
            dummy->next = new ListNode(head2->val);
            dummy = dummy->next;
            head2 = head2->next;
        }
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return nullptr;
        }
        for(int i = 1 ; i < lists.size() ; i++) {
            lists[i] = merge(lists[i], lists[i - 1]);
        }
        return lists.back();
    }
};
