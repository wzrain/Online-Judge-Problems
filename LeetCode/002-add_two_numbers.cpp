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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1, *p2 = l2;
    ListNode* head = new ListNode(0), *p = head;
    int addtmp = 0;
    while (p1 && p2) {
      p->next = new ListNode(0);
      p->next->val = p1->val + p2->val + addtmp;
      addtmp = p->next->val / 10;
      p->next->val %= 10;
      p = p->next;
      p1 = p1->next;
      p2 = p2->next;
    }
    while (p1) {
      p->next = new ListNode(0);
      p->next->val = p1->val + addtmp;
      addtmp = p->next->val / 10;
      p->next->val %= 10;
      
      p = p->next;
      p1 = p1->next;
    }
    while (p2) {
      p->next = new ListNode(0);
      p->next->val = p2->val + addtmp;
      addtmp = p->next->val / 10;
      p->next->val %= 10;
      p = p->next;
      p2 = p2->next;
    }
    if (addtmp) {
      p->next = new ListNode(0);
      p->next->val = 1;
    }
    return head->next;
  }
};