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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    unordered_map<int, ListNode*> mp;
    ListNode* p = head;
    int s = 0;
    while (p) {
      mp[s++] = p;
      p = p->next;
    }
    mp[s] = nullptr;
    if (s == n) return head->next;
    mp[s - n - 1]->next = mp[s - n + 1];
    return head;
  }
};

// two pointers to maintain the distance as n
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* node = new ListNode(0);
    node->next = head;
    ListNode *sl = node, *fs = head;
    for (int i = 0; i < n; ++i) fs = fs->next;
    while (fs) {
      sl = sl->next;
      fs = fs->next;
    }
    sl->next = sl->next->next;
    return node->next;
  }
};