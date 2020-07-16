// dfs solution
// When using dfs to find a loop in a directed graph, only judging by whether a vertex 
// is visited is not enough because we can reach one node from several different starts.
// And we also can't just record the start vertex in the visited array, since we can start
// from the same vertex and reach one vertex from two different routes (which is a loop
// in undirected graphs). We address this problem by explicitly record the current search
// stack, and if the current vertex appears in the previous stack, we find a directed loop. 
class Solution {
public:
    bool dfs(int start, unordered_map<int, vector<int>>& grph, vector<int>& visited, int cur, unordered_set<int>& stk) {
        for (int i = 0; i < grph[cur].size(); ++i) {
            int nx = grph[cur][i];
            if (visited[nx] && stk.find(nx) != stk.end()) return false;
            if (!visited[nx]) {
                visited[nx] = 1;
                stk.insert(nx);
                if (!dfs(start, grph, visited, nx, stk)) return false;
                stk.erase(nx);
            }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> grph;
        
        for (int i = 0; i < prerequisites.size(); ++i) {
            grph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses, 0);
        unordered_set<int> stk;
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i]) continue;
            visited[i] = 1;
            unordered_set<int> stk;
            stk.insert(i);
            if (!dfs(i, grph, visited, i, stk)) return false;
        }
        return true;
    }
};

// topological sort (bfs)
// Use in degrees to imitate the process of taking courses. When there
// are courses with in degree of 0, we can take that course, and its
// suffices' in degree can be decremented. This could be implemented
// via bfs, which is basically emulating some kind of "sequences".
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> grph(numCourses);
        vector<int> degree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); ++i) {
            grph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < numCourses; ++i) {
            if (!degree[i]) {
                q.push(i);
                cnt++;
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < grph[cur].size(); ++i) {
                int nx = grph[cur][i];
                if (!(--degree[nx])) {
                    q.push(nx);
                    cnt++;
                }
            }
        }
        return cnt == numCourses;
    }
};