class StreamChecker {
public:
  StreamChecker(vector<string>& words) {
    head = new node;
    maxlen = 0;
    for (auto str : words) {
      int l = str.length();
      maxlen = max(maxlen, l);
      node* p = head;
      for (int j = l - 1; j >= 0; --j) {
        if (p->mp.find(str[j]) == p->mp.end()) {
          node* cur = new node;
          p->mp[str[j]] = cur;
        }
        p = p->mp[str[j]];
      }
      p->isWord = true;
    }
  }

  bool query(char letter) {
    buffer.push_front(letter);
    if (buffer.size() > maxlen) buffer.pop_back();
    node* p = head;
    for (auto c : buffer) {
      if (p->mp.find(c) == p->mp.end()) return false;
      p = p->mp[c];
      if (p->isWord) return true; // Only check one string (buffer), and early stopping the substring is in the dict.
    }
    return false;
  }
  
private:
  struct node {
    unordered_map<char, node*> mp;
    bool isWord;
    node(bool iw = false) : isWord(iw) {}
  };
  deque<char> buffer; // save space and time than string operations
  node* head;
  int maxlen;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */