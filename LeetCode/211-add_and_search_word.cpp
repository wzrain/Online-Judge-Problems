class WordDictionary {
public:
  /** Initialize your data structure here. */
  WordDictionary() {
    head = new node;
  }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    node* p = head;
    for (auto c : word) {
      if (p->mp.find(c) == p->mp.end()) {
        node* cur = new node;
        p->mp[c] = cur;
      }
      p = p->mp[c];
    }
    p->isWord = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return part(word, 0, head);
  }
  
private:
  struct node {
    unordered_map<char, node*> mp;
    bool isWord;
    node(bool is = false) : isWord(is) {}
  };
  node* head;
  
  bool part(string& wr, int i, node* cur) {
    if (i == wr.length()) return cur->isWord;
    if (cur->mp.find(wr[i]) != cur->mp.end()) {
      return part(wr, i + 1, cur->mp[wr[i]]);
    }
    if (wr[i] != '.') return false;
    for (auto kv : cur->mp) {
      if (part(wr, i + 1, kv.second)) return true; // search every possible match for '.'
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */