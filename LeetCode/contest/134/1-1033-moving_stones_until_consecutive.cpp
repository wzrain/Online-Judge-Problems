// If one of the gap is two, then move the remaining stone to fill the gap.
// Otherwise move the first and last to the middle directly.
// The max step is to move the first and last to the middle one step by one step.
class Solution {
public:
  vector<int> numMovesStones(int a, int b, int c) {
    int mx = max(a, max(b, c)), mn = min(a, min(b, c)), md = a ^ b ^ c ^ mx ^ mn;
    vector<int> res(2, 0);
    res[0] = (mx - md == 2 || md - mn == 2) ? 1 : (mx - md != 1) + (md - mn != 1);
    res[1] = mx - mn - 2;
    return res;
  }
};