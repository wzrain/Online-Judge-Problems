// When looking for consective subsequences, it's crucial to 
// check whether a certain element's adjacent elements have appeared.
// This also contains that sort of "Let the code do the work" thought
// cuz we don't check the whole sequence but only two adjacent elements.
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> st;  // st[i] == j => contains a consecutive sequence
                                 // beginning with i(or j) and ending with j(or i).
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (st.find(nums[i]) != st.end()) continue;
      if (st.find(nums[i] + 1) == st.end() && st.find(nums[i] - 1) == st.end()) {
        st.insert(make_pair(nums[i], nums[i]));
        res = max(res, 1);
      }
      else if (st.find(nums[i] + 1) != st.end() && st.find(nums[i] - 1) == st.end()) {
        st.insert(make_pair(nums[i], st[nums[i] + 1]));
        st[st[nums[i] + 1]] = nums[i];
        res = max(res, st[nums[i]] - nums[i] + 1);
      }
      else if (st.find(nums[i] - 1) != st.end() && st.find(nums[i] + 1) == st.end()) {
        st.insert(make_pair(nums[i], st[nums[i] - 1]));
        st[st[nums[i] - 1]] = nums[i];
        res = max(res,  nums[i] - st[nums[i]] + 1);
      }
      else {
        int e1, e2;
        e1 = st[nums[i] - 1];
        e2 = st[nums[i] + 1];
        st[st[nums[i] + 1]] = e1;
        st[st[nums[i] - 1]] = e2;
        res = max(res, e2 - e1 + 1);
        st.insert(make_pair(nums[i], INT_MAX));
      }
      // In fact all we care about is the left and the right
      // bound of the sequence, so instead of use four ifs, it's
      // good to just track the left and right, which makes the
      // code clean and logic clear.
      // The previous lines could be simplified as follows:
      /*
       * int l = nums[i], r = nums[i];
       * st[nums[i]] = nums[i];
       * if (st.find(nums[i] + 1) != st.end()) r = st[nums[i] + 1];
       * if (st.find(nums[i] - 1) != st.end()) l = st[nums[i] - 1];
       * st[l] = r;
       * st[r] = l;
       * res = max(res, r - l + 1);
       */
    }
    return res;
  }
};

// Instead of recording the bound of sequences, record the length of each consequence.
// This borrows the idea of the union-find set. Here if two elements are in one sequence,
// They should be in the same union-find set. And since every update happens in the bound
// of sequences, we set the father as two bound elements and update their values.
// The intuition of the union-find set here is that "consecutive" means "grouped".
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> st;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (st.find(nums[i]) != st.end()) continue;
      int l = nums[i], r = nums[i];
      st[nums[i]] = 1;
      if (st.find(nums[i] + 1) != st.end()) r = st[nums[i] + 1] + nums[i];
      if (st.find(nums[i] - 1) != st.end()) l = nums[i] - st[nums[i] - 1];
      st[l] = st[r] = r - l + 1;
      res = max(res, st[l]);
    }
    return res;
  }
};