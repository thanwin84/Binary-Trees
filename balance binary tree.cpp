class Solution {
public:
    int solve(TreeNode * root, bool &flag){
        if (root == nullptr){
            return 0;
        }
        int left = solve(root->left, flag);
        int right = solve(root->right, flag);
        if (abs(left - right) > 1) flag = false;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        solve(root, flag);
        return flag;
    }
};
