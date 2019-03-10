// priority queue
class Solution_PQ {
public:
  struct building {
    int idx, left, right, height;
    building(int i, int l, int r, int h) : idx(i), left(l), right(r), height(h) {}
  };
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    int next_pos = -1, cur_h = 0;
    vector<pair<int, int>> res;
    
    auto cmp = [](building b1, building b2) {
      if (b1.height == b2.height) return b1.right <= b2.right;
      return b1.height < b2.height;
    };
    priority_queue<building, vector<building>, decltype(cmp)> bpq(cmp);
    //The element of the priority queue can actually be only a pair of <height, right>.
     
    for (int i = 0; i < buildings.size(); ++i) {     
      while (!bpq.empty() && buildings[i][0] > next_pos) {
        while(!bpq.empty() && next_pos >= bpq.top().right) bpq.pop();
        if (bpq.empty()) cur_h = 0;
        else cur_h = bpq.top().height;
        if (res.size() && res.back().first == next_pos && res.back().second > cur_h) {
          res.back().second = cur_h;
        }
        else res.push_back(make_pair(next_pos, cur_h));
        if (!bpq.empty()) next_pos = bpq.top().right;
      }
      if (buildings[i][2] > cur_h) {
        if (res.size() && res.back().first == buildings[i][0] 
                       && res.back().second < buildings[i][2]){
          res.back().second = buildings[i][2];
        }
        else res.push_back(make_pair(buildings[i][0], buildings[i][2]));
      }
      
      bpq.push(building(i, buildings[i][0], buildings[i][1], buildings[i][2]));
      next_pos = bpq.top().right;
      cur_h = bpq.top().height;
    }
    while (!bpq.empty()) { 
      while(!bpq.empty() && next_pos >= bpq.top().right) bpq.pop();
      if (bpq.empty()) cur_h = 0;
      else cur_h = bpq.top().height;
      if (res.size() && res.back().first == next_pos && res.back().second > cur_h) {
        res.back().second = cur_h;
      }
      else res.push_back(make_pair(next_pos, cur_h));
      if (!bpq.empty()) next_pos = bpq.top().right;
    }
    return res;
  }
};

// divide and conquer
class Solution {
public:
  int Max(int a, int b) {
    return a > b ? a : b;
  }
  vector<pair<int, int>> getPartSkyline(vector<vector<int>>& part) {
    if (part.size() == 1) {
      vector<pair<int, int>> res1;
      res1.push_back(make_pair(part[0][0], part[0][2]));
      res1.push_back(make_pair(part[0][1], 0));
      return res1;
    }
    int mid = part.size() / 2;
    vector<vector<int>> left_points(part.begin(), part.begin() + mid);
    vector<vector<int>> right_points(part.begin() + mid, part.end())
    vector<vector<int>> left = getPartSkyline(left_points);
    vector<vector<int>> right = getPartSkyline(right_points);
    vector<vector<int>> res;
    int ml = 1, mr = 0, ch = left[0][1];
    res.push_back()
    while (ml != left.size() || m2 != right.size()) {
      if (left[m1])
    }
  }
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    std::vector<std::pair<int, int>> res;
    return res;
  }
};