class Solution {
public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> stk, res(n, 0);
    int cur = 0, last = 0;
    for (auto str : logs) {
      int id = 0, i = 0;
      // calculate the id
      while (str[i] != ':') {
        id *= 10;
        id += (str[i++] - '0');
      }
      int time = 0, j = str.length() - 1, bs = 1;
      // calculate the moment
      while (str[j] != ':') {
        time += (bs * (str[j--] - '0'));
        bs *= 10;
      }
      // The inclusion or exclusion of the current time depends on start or end.
      // If it's a start moment, the current task in the stack is paused and the
      // previous execution time should be added to it, and a new task starts. If
      // the previous task is a start moment (last == 0), the execution includes the
      // cur moment.
      if (str[i + 1] == 's') {
        if (!stk.empty()) stk.back() += (time - cur - last);
        stk.push_back(0);
        last = 0;
      }
      // If the task ends, this specific task must be at the top of the stack, so 
      // the stk.back() is the time that this task has already been executed. If this
      // task has just started in the last timestamp (stk.back() == 0) the execution time
      // should include the cur moment, which is the start moment of the task. Otherwise,
      // the cur moment is a ending moment of another task and is not included in this task's
      // execution time.
      else {
        res[id] += time - cur + stk.back() + (stk.back() == 0);
        stk.pop_back();
        last = 1;
      }
      cur = time;
    }
    return res;
  }
};