/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* nx = head->next;
        ListNode* res = reverseList(nx);
        nx->next = head;
        head->next = NULL;
        return res;
    }
    int calc(ListNode* head) {
        int len = 1;
        ListNode* p = head;
        while (p->next) {
            p = p->next;
            len++;
        }
        return len;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        int len = calc(head);
        ListNode* p = head;
        for (int i = 0; i < len / 2 - 1; ++i) {
            p = p->next;
        }
        ListNode* rear = reverseList(p->next);
        while (rear) {
            if (head->val != rear->val) return false;
            head = head->next;
            rear = rear->next;
        }
        return true;
    }
};