// In a complete binary tree, if the left and right subtree height is same, then the number of node is 2^h - 1
class Solution {
public:
    int rightHeight(TreeNode * root){
        int h = 0;
        TreeNode * current = root;
        while (current){
            h++;
            current = current->right;
        }
        return h;
    }
    int leftHeight(TreeNode * root){
        int h = 0;
        TreeNode * current = root;
        while (current){
            h++;
            current = current->left;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if (lh == rh) {
            return pow(2, lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
