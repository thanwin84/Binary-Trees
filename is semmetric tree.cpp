class Solution {
public:
    bool isSemmetricHelp(TreeNode * left, TreeNode * right){
        if (left == nullptr || right == nullptr){
            return left == right;
        }
        if (left->val != right->val) {
            return false;
        }
        return isSemmetricHelp(left->left, right->right) && isSemmetricHelp(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isSemmetricHelp(root->left, root->right);
    }
};
// time: O(n) and stack space is O(N) assuming if the tree skewed tree
