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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pm = dummy;
        for (int i = 0; i < m - 1; ++i) {
            if (!pm->next) return head;
            pm = pm->next;
        }
        
        ListNode *nx = pm->next, *pn = pm;
        pm = nx;
        for (int i = m; i <= n; ++i) {
            if (!nx) break;
            ListNode* tmp = nx->next;
            nx->next = pn;
            pn = nx;
            nx = tmp;
        }
        
        if (pm->next) pm->next->next = pn;
        pm->next = nx;
        return dummy->next;
    }
};