// Sort each string as a key for map finding.
class Solution_sort {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> output;
    unordered_map<string, vector<string>> res;
    for (auto s : strs) {
      string cps = s;
      sort(s.begin(), s.end());
      if (res.find(s) == res.end()) {
        vector<string> to_ins;
        to_ins.push_back(cps);
        res.insert(make_pair(s, to_ins));
      }
      else {
        res.at(s).push_back(cps);
      }
    }
    for (auto ele : res) {
      output.push_back(ele.second);
    }
    return output;
  }
};

// Use self-defined hash key for string to avoid sorting.
// Use prime numbers to create unique hash values.
class Solution_hash {
public:
  constexpr static int primes[26] = {2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
  
  struct hashFunc {
    std::size_t operator()(const string& key) const {
      std::size_t h = 1;
      for (auto c : key) {
        h *= primes[c - 'a'];
      }
      return h;
    }
  };
  struct equalKey {
    bool operator()(const string& s1, const string& s2) const {
      return hashFunc{}(s1) ==  hashFunc{}(s2);
    }
  };
  
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> output;
    unordered_map<string, vector<string>, hashFunc, equalKey> res;
    for (auto s : strs) {
      if (res.find(s) == res.end()) {
        vector<string> to_ins;
        to_ins.push_back(s);
        res.insert(make_pair(s, to_ins));
      }
      else {
        res.at(s).push_back(s);
      }
    }
    for (auto ele : res) {
      output.push_back(ele.second);
    }
    return output;
  }
};
