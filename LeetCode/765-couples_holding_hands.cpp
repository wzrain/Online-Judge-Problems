// Borrow the idea of "first missing integer" and try to do
// cyclic swapping. The difference is that here we don't require
// every pair to be at its corresponding indices. So we transform
// the problem by sending corresponding pairs back to its indices.
// For a initial pair, we send it back to the indices corresponding
// to the first element. If there is already another pair there, 
// that means a swap has to happen, and the first element need to
// swap the second element in the array to make a complete pair,
// and we find the new corresponding indices of the updated 
// initial pair, the first element of which is updated from
// that swap operation.
// A swap is necessary if it sends at least one element back without
// moving a settled element. A swap that makes both involved element
// settled is even better. The swapping operations in the "send-back" 
// stage and the "cyclic swapping" stage are all of these two kinds.
// If these kinds of operations do not belong to an optimal solution,
// say swap a and b and make a settled, and then use k steps to make
// b settled, there must be another way that b is settled in k - 1 
// steps or a and b are both settled in k steps. For the former case,
// we could easily replace the k-step solution with the k - 1-step one.
// For the latter, we could change the sequence of swapping to make it
// contain the direct swapping between a and b. So the a-b swapping
// must be in an optimal solution. So we could just use the cyclic
// swapping as a greedy strategy.
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int nn = row.size();
        vector<int> copy(nn, -1);
        int cnt = 0;
        for (int i = 0; i < nn; i += 2) {
            int cur = (row[i] & 1) ? row[i] - 1 : row[i];
            while (copy[cur] != -1) {
                swap(copy[cur + 1], row[i]);
                cur = (row[i] & 1) ? row[i] - 1 : row[i];
                cnt++;
            }
            copy[cur] = row[i];
            copy[cur + 1] = row[i + 1];
        }
        
        for (int i = 0; i < nn; ++i) {
            int a = i, b = (i & 1) ? i - 1 : i + 1;
            while (copy[i] != a && copy[i] != b) {
                int na = copy[i], nb = (copy[i] & 1) ? copy[i] - 1 : copy[i] + 1;
                if (copy[na] == a || copy[na] == b || 
                    copy[nb] == na || copy[nb] == nb) {
                    swap(copy[i], copy[na]);
                }
                else swap(copy[i], copy[nb]);
                cnt++;
            }
        }
        return cnt;
    }
};