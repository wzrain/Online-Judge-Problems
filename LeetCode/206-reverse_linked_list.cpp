/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// non-recursive
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* p = head, *q = head->next;
    while (q) {
      ListNode* tmp = q->next;
      q->next = p;
      p = q;
      q = tmp;
    }
    head->next = NULL;
    return p;
  }
};

// recursive
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* res = reverseList(head->next); 
    head->next->next = head;
    head->next = NULL;
    return res;
  }
};