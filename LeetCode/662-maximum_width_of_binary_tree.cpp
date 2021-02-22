/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
        while (!q.empty()) {
            int sz = q.size();
            int mn = sz, mx = 0;
            // Instead of recording absolute indices, store relative indices to prevent overflow.
            // Note that when we offsetted one layer, the relative distances still hold, which 
            // still support idx * 2 calculation for next layer's indices.
            int offset = -1;
            while (sz--) {
                int idx = q.front().first;
                TreeNode* cur = q.front().second;
                q.pop();
                mx = max(idx, mx);
                mn = min(idx, mn);
                if (cur->left) {
                    if (offset < 0) offset = idx * 2;
                    q.push(make_pair(idx * 2 - offset, cur->left));
                }
                if (cur->right) {
                    if (offset < 0) offset = idx * 2 + 1;
                    q.push(make_pair(idx * 2 + 1 - offset, cur->right));
                }
            }
            res = max(res, mx - mn + 1);
        }
        return res;
    }
};