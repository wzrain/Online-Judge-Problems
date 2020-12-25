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

// separate into the sum of a subtree and the rest of the sum
// the closer these two sums are, the larger the product
class Solution {
public:
    int getSum(TreeNode* root, int tgt, int& res) {
        if (!root) return 0;
        int sum = root->val + getSum(root->left, tgt, res) + getSum(root->right, tgt, res);
        if (abs(tgt - sum) < abs(tgt - res)) res = sum;
        return sum;
    }
    int maxProduct(TreeNode* root) {
        int tgt = 0, res = 0;
        int total = getSum(root, tgt, res);
        tgt = total >> 1;
        getSum(root, tgt, res);
        return ((long)res * (total - res)) % (1000000007);
    }
};