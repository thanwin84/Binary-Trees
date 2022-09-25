// time: O(n) and space: O(n) [ stack space]
class Solution {
public:
    bool solve(TreeNode * p, TreeNode * q){
        if (p == nullptr && q == nullptr){
            return true;
        }
        if (p == nullptr || q == nullptr){
            return false;
        }
        if (p->val != q->val) return false;
        bool left = solve(p->left, q->left);
        bool right = solve(p->right, q->right);
        return left && right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p, q);
    }
};
