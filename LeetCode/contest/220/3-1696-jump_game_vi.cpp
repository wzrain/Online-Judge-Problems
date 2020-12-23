// At first we need to realize that every non-negative number contributes to the final results. So the tricky 
// part is to deal with two non-negative numbers with more than k consecutive negative numbers in between. 
// Then the intuition would be to maintain a monotonous queue, and only save <index, sum> pairs sorted by sum in 
// an ascending order, so that every element in the queue is possible to contribute to the final result, 
// where the elements not in the queue is guaranteed to be irrelevant with the result.
// Then actually the intuition could be generalized to the entire problem, and not just in dealing with 
// negative numbers. The monotonous queue saves elements <i, sum> where sum is the largest possible results with 
// nums[i] involved after considering nums[0, i]. If nums[i] is a non-negative number, then it must become the 
// first and only element in the queue afterwards. So basically the monotonous queue automatically start 
//dealing with negative numbers without us having to calculate the "next" non-negative element and so on.
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int len = nums.size();
        deque<pair<int, int>> dq;
        dq.push_back(make_pair(0, nums[0]));
        for (int i = 1; i < len; ++i) {
            while (!dq.empty() && i - dq.front().first > k) dq.pop_front();
            int tmp = nums[i] + dq.front().second;
            while (!dq.empty() && tmp >= dq.back().second) dq.pop_back();
            dq.push_back(make_pair(i, tmp));
        }
        return dq.back().second;
    }
};