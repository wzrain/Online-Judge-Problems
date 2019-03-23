// based on minimum mono stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      vector<pair<int, int>> stk;
      int sqr = 0;
      for (int i = 0; i < heights.size(); ++i) {
        int l = 0;
        while (!stk.empty() && heights[i] < heights[stk.back().first]) {
          int tmp = heights[stk.back().first] * (i - stk.back().first + stk.back().second);
          if (sqr < tmp) sqr = tmp;
          l += (stk.back().second + 1);
          stk.pop_back();
        }
        stk.push_back(make_pair(i, l));
      }
      while (!stk.empty()) {
        int tmp = heights[stk.back().first] * (heights.size() - stk.back().first + stk.back().second);
        if (sqr < tmp) sqr = tmp;
        stk.pop_back();
      }
      return sqr;
    }
};

// Notice that the "len" info in the pair is actually the distance 
// between two neighboring heights in the stack. So no need to keep
// an independent value for this info.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      vector<int> stk;
      int sqr = 0;
      for (int i = 0; i < heights.size(); ++i) {
        int l = 0;
        while (!stk.empty() && heights[i] < heights[stk.back()]) {
          int tmph = heights[stk.back()];
          stk.pop_back();
          int tmplen = i;
          if (!stk.empty()) tmplen -= (stk.back() + 1);
          if (sqr < tmph * tmplen) sqr = tmph * tmplen;
        }
        stk.push_back(i);
      }
      while (!stk.empty()) {
        int tmph = heights[stk.back()];
        stk.pop_back();
        int tmplen = heights.size();
        if (!stk.empty()) tmplen -= (stk.back() + 1);
        if (sqr < tmph * tmplen) sqr = tmph * tmplen;
      }
      return sqr;
    }
};