// time: O(N)
class Solution {
public:
    bool solve(TreeNode * root, long int _min,long int _max){
        if (root == nullptr){
            return true;
        }
        
        if (root->val > _min && root->val < _max){
            bool left = solve(root->left, _min, root->val);
            bool right = solve(root->right, root->val, _max);
            return left && right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};
// We can also solve this by using inorder treversal
