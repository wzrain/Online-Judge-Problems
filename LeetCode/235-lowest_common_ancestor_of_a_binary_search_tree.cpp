/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        TreeNode* res = root;
        while ((p->val - res->val) * (q->val - res->val) > 0) {
            if (p->val < res->val) res = res->left;
            else res = res->right;
        }
        return res;
    }
};