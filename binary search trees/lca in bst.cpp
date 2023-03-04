class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        // we only have treverse until p and q
        if (p->val == root->val) return p;
        if (q->val == root->val) return q;
        TreeNode * left = nullptr;
        TreeNode * right = nullptr;
        // Either p or q should exists, only then we should visit the path
        if (p->val < root->val || q->val < root->val){
            left = lowestCommonAncestor(root->left, p, q);
        }
         // Either p or q should exists, only then we should visit the path
        if (p->val > root->val || q->val > root->val){
            right = lowestCommonAncestor(root->right, p, q);
        }
        // left = null means, in that path p or q doesn't exist
        if (left == nullptr){
            return right;
        }
        // right = null means, in that path p or q doesn't exist
        else if (right == nullptr){
            return left;
        }
        // p and q exists in both path, so the rool will be the lca
        else {
            return root;
        }
    }
};
