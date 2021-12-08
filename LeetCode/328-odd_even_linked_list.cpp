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
        if (!head || !head->next) return head;
        ListNode* odd = head, *po = odd;
        ListNode* even = head->next, *pe = even;
        while (pe && pe->next) {
            ListNode* no = pe->next;
            ListNode* ne = no->next;
            po->next = no;
            pe->next = ne;
            po = no;
            pe = ne;
        }
        po->next = even;
        return odd;
    }
};