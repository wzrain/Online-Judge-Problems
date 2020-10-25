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

// idea similar to 092
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = head;
        int len = 0;
        while (cur) {
            len++;
            cur = cur->next;
        }
        cur = dummy;
        ListNode* nx = head;
        for (int i = 0; i <= len - k; i += k) {
            ListNode* start = nx;
            for (int j = 0; j < k; ++j) {
                ListNode* tmp = nx->next;
                nx->next = cur;
                cur = nx;
                nx = tmp;
            }
            start->next->next = cur;
            start->next = nx;
            cur = start; // the previous "cur" has been moved to the front!
        }
        return dummy->next;
    }
};