/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// self-implemented priority queue
// In linked lists, it's good to directly do manipulations on the node itself 
// rather than new a new pointer as a copy if unnecessary.
class Solution {
public:
  void push(vector<int>& h, vector<ListNode*>& idxes, int x) {
    h.push_back(x);
    int pidx = h.size() - 1, idx = pidx >> 1;
    while (idx > 0 && idxes[x]->val < idxes[h[idx]]->val) {
      h[pidx] = h[idx];
      h[idx] = x;
      pidx = idx;
      idx >>= 1;
    }
  }
  int pop(vector<int>& h, vector<ListNode*>& idxes) {
    int res = h[1];
    h[1] = h.back();
    h.pop_back();
    if (h.size() <= 2) return res;
    int x = h[1], pidx = 1, idx = 2;
    if (h.size() > 3 && idxes[h[2]]->val > idxes[h[3]]->val) idx = 3;
    while (idx < h.size() && idxes[x]->val > idxes[h[idx]]->val) {
      h[pidx] = h[idx];
      h[idx] = x;
      pidx = idx;
      int tmp = idx;
      if (tmp * 2 >= h.size()) break;
      if (tmp * 2 < h.size() && idxes[h[idx]]->val > idxes[h[tmp * 2]]->val) idx = tmp * 2;
      if (tmp * 2 + 1 < h.size() && idxes[h[idx]]->val > idxes[h[tmp * 2 + 1]]->val) idx = tmp * 2 + 1;
    }
    return res;
  }
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> h;
    ListNode* head = new ListNode(0), *p = head;
    h.push_back(0);
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i]) push(h, lists, i);
    }
    while (h.size() > 1) {
      int ix = pop(h, lists);
      // Here no need to create a new pointer with the same value as lists[ix].
      // Directly link to the original pointer to save time and space.
      p->next = lists[ix];
      p = p->next;
      // Modify the original link list itself rather than create a "tracking" pointer.
      lists[ix] = lists[ix]->next; 
      if (lists[ix]) push(h, lists, ix);
    }
    return head->next;
  }
};

// Use std::priority_queue
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = new ListNode(0), *p = head;
    auto cmp = [](ListNode* l1, ListNode* l2) {
      return l1->val > l2->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i]) pq.push(lists[i]);
    }
    while (!pq.empty()) {
      ListNode* tmp = pq.top();
      pq.pop();
      p->next = tmp; 
      p = p->next;
      if (tmp->next) pq.push(tmp->next);
    }
    return head->next;
  }
};

// recursive divide & conquer solution
// actually the process of merge sort
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    }
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return NULL;
    if (lists.size() == 1) return lists[0];
    vector<ListNode*> ls1, ls2;
    for (int i = 0; i < lists.size(); ++i) {
      if (i < lists.size() / 2) ls1.push_back(lists[i]);
      else ls2.push_back(lists[i]);
    }
    ListNode* l1 = mergeKLists(ls1), *l2 = mergeKLists(ls2);
    return mergeTwoLists(l1, l2);
  }
};