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
class Solution_DC {
public:
  int Max(int a, int b) {
    return a > b ? a : b;
  }
  vector<pair<int, int>> getPartSkyline(vector<vector<int>>& part, int low, int high) {
    if (low > high) return {};
    if (low == high) {
      vector<pair<int, int>> res1;
      res1.push_back(make_pair(part[low][0], part[low][2]));
      res1.push_back(make_pair(part[low][1], 0));
      return res1;
    }
    int mid = (low + high) / 2;
    vector<pair<int, int>> left = getPartSkyline(part, low, mid);
    vector<pair<int, int>> right = getPartSkyline(part, mid + 1, high);
    vector<pair<int, int>> res;
    int ml = 0, mr = 0, cur_h = -1, tmp_h;
    while (ml != left.size() || mr != right.size()) {
      if (ml == left.size()) {
        while (mr != right.size()) {
          res.push_back(right[mr++]);
        }
        break;
      }
      if (mr == right.size()) {
        while (ml != left.size()) {
          res.push_back(left[ml++]);
        }
        break;
      }
      if (left[ml].first == right[mr].first) {
        tmp_h = Max(left[ml].second, right[mr].second);
        if (tmp_h != cur_h){
          res.push_back(make_pair(left[ml].first, tmp_h));
        }
        ml++;
        mr++;
      }
      else if (left[ml].first < right[mr].first) {
        if (mr == 0) {
          tmp_h = left[ml].second;
          res.push_back(make_pair(left[ml].first, left[ml].second));
        }
        else {
          tmp_h = Max(left[ml].second, right[mr - 1].second);
          if (tmp_h != cur_h) {
            res.push_back(make_pair(left[ml].first, tmp_h));
          }
        }
        ml++;
      }
      else  {
        tmp_h = Max(left[ml - 1].second, right[mr].second);
        if (tmp_h != cur_h) {
          res.push_back(make_pair(right[mr].first, tmp_h));
        }
        mr++;
      }
      cur_h = tmp_h;
    }
    return res;
  }
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    return getPartSkyline(buildings, 0, buildings.size() - 1);
  }
};