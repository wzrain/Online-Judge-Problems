// each bus is a node, where every stop is a "direction"
class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if (S == T) return 0; // If we check q.front() rather than the stops when we push in,
                          // this line is unecessary and start should be increased at the end of the loop
    unordered_map<int, vector<int>> stop_buses;
    unordered_set<int> visited;
    queue<int> q;
    for (int i = 0; i < routes.size(); ++i) {
      for (int j = 0; j < routes[i].size(); ++j) {
        stop_buses[routes[i][j]].push_back(i);
      }
    }
    q.push(T);
    //visited.insert(T); // Instead of recording visited stops, 
                         // still need to record visited buses, and if the buses
                         // are visited, stops of these buses must be visited.
                         // So only recording visited buses would be ok.
    int start = 0;
    while (!q.empty()) {
      start++;
      int sz = q.size();
      for (int ss = 0; ss < sz; ++ss) {
        //if (q.front() == S) return start;
        for (auto b : stop_buses[q.front()]) {
          if (visited.find(b) != visited.end()) continue;
          visited.insert(b);
          for (auto s : routes[b]) {
            if (s == S) return start;
            //if (visited.find(s) != visited.end()) continue;
            if (s != T) q.push(s);
            //visited.insert(s);
          }
          //routes[b].clear(); // If we record the visited stops, make sure the same bus 
                               // won't be visited again. It will waste time since there will be
                               // more double loops to check where each s of this very bus
                               // is visited. Although it resulted in nothing, it cost a lot
                               // of time.
        }
        q.pop();
      }
      //start++;
    }
    return -1;
  }
};