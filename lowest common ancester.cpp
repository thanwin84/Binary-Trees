class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (p->val == root->val) return p;
        if (q->val == root->val) return q;
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr){
            return right;
        }
        else if (right == nullptr){
            return left;
        }
        else {
            return root;
        }
    }
};

// time: O(n) and stack space: O(H)
