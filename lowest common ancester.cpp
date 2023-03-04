
// naive solution would be to store all the nodes from root to p and root to q in two separate arrays. then the last common 
// node from this two array will be the lca
// but in this approach we are using extra space which is O(n)

///////OPTIMIZED APPROACH/////////////////
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        // we only have TO treverse until p and q
        if (p->val == root->val) return p;
        if (q->val == root->val) return q;
        
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right = lowestCommonAncestor(root->right, p, q);
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

// time: O(n) and stack space: O(H)
