# time: O(n) and space: O(1)
class Solution {
public:
    int solve(TreeNode* root,int &result) {
        if (!root){
            return 0;
        }
        // maximum value will not contibute in max path sum
        // adding negative value to another value[positive or negative] will always decrease value
        int left = max(0, solve(root->left, result));
        int right = max(0, solve(root->right, result));
        // consireding curve path
        result = max(result, root->val + left + right);
        // considering left or right path
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root){
        int result = INT_MIN;
        solve(root, result);
        return result;
    }
};
