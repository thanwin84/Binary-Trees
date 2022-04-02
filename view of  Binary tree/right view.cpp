// using BFS
// Time: O(n) 
// space: q size will be at max n /2 so space complexity is O(n)

// Using preorder recursion
// but here we will treverse right right, then left
// time: O(n) and space: O(H of Tree)
class Solution {
public:
    vector<int> solve(TreeNode*root, int level, vector<int> &result){
        if (!root){
            return result;
        }
        if (level == result.size()){
            result.push_back(root->val);
        }
        solve(root->right, level + 1, result);
        solve(root->left, level + 1, result);
        return result;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        return solve(root, 0, result);
    }
};
