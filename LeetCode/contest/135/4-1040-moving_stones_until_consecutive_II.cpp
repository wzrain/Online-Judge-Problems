// The number of "hole"s are important. Before forming a consecutive array,
// we need to fill all the holes between the elements.
// For the max step, we need to move the stones to as many holes as possible.
// So just consider the holes between 0 to n - 2 (which is actually putting the 
// right end stone INTO the remaining array) or 1 to n - 1 (which is putting
// the left end stone INTO the remaining array). Note that this is not a
// recursive process because we can choose where to put the end stone INTO a 
// subarray. So although there might be no chance that we can cover every hole
// between 0 to n - 1, there will always be a way to cover 0 to n - 2 or 1 to
// n - 1 by finessing the position of the first moved end stone.
// For the min step, consider the final consecutive array, which has the length
// of n. To cover as least holes as possible, we need to make sure that there are
// as many elements unmoved in this final array. So just explore every n-lengthed
// array starting with each element, and calculate how many elements are originally
// in this array, and choose the one with the most original elements. 
class Solution {
public:
  int bisearch(int tgt, int l, int r, vector<int>& stones) {
    if (l == r) return l - 1;
    int mid = (l + r) / 2;
    if (tgt >= stones[mid]) return bisearch(tgt, mid + 1, r, stones);
    else return bisearch(tgt, l, mid, stones);
  }
  vector<int> numMovesStonesII(vector<int>& stones) {
    int n = stones.size();
    vector<int> res(2, 0), gapsum(n, 0);
    sort(stones.begin(), stones.end());
    for (int i = 1; i < n; ++i) {
      gapsum[i] = gapsum[i - 1] + stones[i] - stones[i - 1] - 1;
    }
    res[1] = gapsum[n - 2] - gapsum[1] + (max(gapsum[1], stones[n - 1] - stones[n - 2] - 1));
    int minhole = INT_MAX, idx = 0;
    for (int i = 0; i < n - 1; ++i) {
      int cur = stones[i], last = cur + n - 1;
      // idx = bisearch(last, 0, n, stones);
      while (idx < n && stones[idx] <= last) idx++;  
      idx--;                                             // Binary search is used to find the last element covered 
                                                         // in this array, and gives an O(logn). But this strategy
                                                         // didn't use the previously searched results. So just move
                                                         // the idx along with the loop, so there are no extra O(logn).
      int curhole = gapsum[idx] - gapsum[i] + last - stones[idx];
      if (curhole == 1 && last != stones[idx]) continue; // The only situation is that there are n - 1 elements, 
                                                         // all of which are consecutive in that array, which means 
                                                         // the only remaining stone is an end stone AND cannot be moved
                                                         // into that array. Just ignore this situation would be OK.
      minhole = min(minhole, curhole);
    }
    res[0] = minhole;
    return res;
  }
};