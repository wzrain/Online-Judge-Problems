// priority queue
class Solution {
public:
  struct building {
    int idx, left, right, height;
    building(int i, int l, int r, int h) : idx(i), left(l), right(r), height(h) {}
  };
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    int cur_pos, cur_h = 0;
    vector<pair<int, int>> res;
    unordered_set<int> poped_building;
    auto cmp = [](building b1, building b2) {return b1.right >= b2.right;};
    priority_queue<building, vector<building>, decltype(cmp)> bpq(cmp);
    auto cmp2 = [](building b1, building b2) {return b1.height <= b2.height;};
    priority_queue<building, vector<building>, decltype(cmp2)> hq(cmp2);
    for (int i = 0; i < buildings.size(); ++i) {
      cur_pos = buildings[i][0];
      while (!bpq.empty() && cur_pos > bpq.top().right){ 
        poped_building.insert(bpq.top().idx);
        while (!hq.empty() && poped_building.find(hq.top().idx) != poped_building.end()) {
          hq.pop();
        }
        if (hq.empty()) cur_h = 0;
        else cur_h = hq.top().height;
        if (bpq.top().height > cur_h) {
          if (res.size() && res[res.size() - 1].first == bpq.top().right 
                          && res[res.size() - 1].second > cur_h) {
            res[res.size() - 1].second = cur_h;
          }
          else res.push_back(make_pair(bpq.top().right, cur_h));
        }
        
        bpq.pop();
      }
      if (cur_h < buildings[i][2]) {
        cur_h = buildings[i][2];
        if (res.size() && res[res.size() - 1].first == buildings[i][0] 
                        && res[res.size() - 1].second < buildings[i][2]) {
          res[res.size() - 1].second = buildings[i][2];
        }
        else res.push_back(make_pair(buildings[i][0], buildings[i][2]));
      }
      bpq.push(building(i, buildings[i][0], buildings[i][1], buildings[i][2]));
      hq.push(building(i, buildings[i][0], buildings[i][1], buildings[i][2]));
    }
    while (!bpq.empty()){ 
      poped_building.insert(bpq.top().idx);
      while (!hq.empty() && poped_building.find(hq.top().idx) != poped_building.end()) {
        hq.pop();
      }
      if (hq.empty()) cur_h = 0;
      else cur_h = hq.top().height;
      if (bpq.top().height > cur_h) {
        if (res.size() && res[res.size() - 1].first == bpq.top().right 
                          && res[res.size() - 1].second > cur_h) {
            res[res.size() - 1].second = cur_h;
          }
          else res.push_back(make_pair(bpq.top().right, cur_h));
      }

      bpq.pop();
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