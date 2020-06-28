// The key observation is that when a number appears multiple
// times, every time could be processed independently. If we 
// only consider the total count of a number, when one of them
// is popped, it's hard to find the right position in the count
// - 1 set. Instead when it reaches count - 1, just push it into
// the corresponding count - 1 stack and that stack exactly 
// represents the sequence of popping.
// Actually we don't need map to maintain the order and erase to
// find the next largest count, because unlike the shortest path
// algorithm where the map is used, the count of a number is 
// incremented one by one, and the stk's key is exactly from 1 to
// mx which is the largest count.
class FreqStack {
public:
    unordered_map<int, int> cnt;
    // map<int, vector<int>> stk;
    unordered_map<int, vector<int>> stk;
    int mx;
    FreqStack() {
        mx = 0;
    }
    
    void push(int x) {
        cnt[x]++;
        stk[cnt[x]].push_back(x);
        mx = max(mx, cnt[x]);
    }
    
    int pop() {
        // int mx = (stk.end()--)->first;
        int res = stk[mx].back();
        stk[mx].pop_back();
        if (stk[mx].empty()) mx--;//stk.erase(mx);
        cnt[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */