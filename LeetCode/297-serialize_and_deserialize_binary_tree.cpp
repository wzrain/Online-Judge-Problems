/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string itos(long val) {
        string res = "";
        int sign = 1;
        if (val < 0) {
            val = -val;
            sign = -1;
        }
        while (val) {
            char c = (val % 10) + '0';
            res = c + res;
            val /= 10;
        }
        if (sign == -1) res = '-' + res;
        return res;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        string res = "[";
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        // The following solution does not get rid of the
        // last all-null level. So the cnt is actually useless.
        // while (!q.empty() || cnt) {
        //     TreeNode* cur = q.front();
        //     q.pop();
        //     if (cur) {
        //         res += (itos(cur->val) + ',');
        //         cnt--;
        //         q.push(cur->left);
        //         if (cur->left) cnt++;
        //         q.push(cur->right);
        //         if (cur->right) cnt++;
        //     }
        //     else {
        //         res += "null,";
        //     }
        // }

        // We need to count the non-null value, and check for
        // every level. So the all-null level is removed.
        while (cnt) {
            int sz = q.size();
            while (sz--) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur) {
                    res += (itos(cur->val) + ',');
                    cnt--;
                    q.push(cur->left);
                    if (cur->left) cnt++;
                    q.push(cur->right);
                    if (cur->right) cnt++;
                }
                else {
                    res += "null,";
                }
            }
        }
        res.back() = ']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return NULL;
        int idx = 1, len = data.length();
        TreeNode* root = NULL;
        // Use double pointers to change each node itself.
        queue<TreeNode**> q;
        q.push(&root);
        while (idx < len) {
            long tmp = 0;
            int sign = 1;
            TreeNode** cur = q.front();
            q.pop();
            if (data[idx] == 'n') {
                idx += 4;
                *cur = NULL;
            }
            else {
                if (data[idx] == '-') {
                    sign = -1;
                    idx++;
                }
                while (data[idx] >= '0' && data[idx] <= '9') {
                    tmp *= 10;
                    tmp += (data[idx] - '0');
                    idx++;
                }
                tmp *= sign;
                
                *cur = new TreeNode(tmp);   
                q.push(&((*cur)->left));
                q.push(&((*cur)->right));
            }
            idx++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));