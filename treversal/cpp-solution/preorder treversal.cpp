class Solution {
public:
    vector<int> result;
    void solve(TreeNode * root){
        if (!root){
            return;
        }
        result.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        solve(root);
        return result;
    }
};
// iterative approach
// time: O(n) and space O(height of the tree)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root){
            return result;
        }
        vector<TreeNode*> stack;
        stack.push_back(root);
        while (stack.size() > 0){
            TreeNode * current = stack.back();
            stack.pop_back();
            result.push_back(current->val);
            
            // pushing right first, coz we need the to print the left first
            // by doing it, we are also keeping track of right subtree of proceesed node
            if (current->right){
                stack.push_back(current->right);
            }
            if (current->left){
                stack.push_back(current->left);
            }
        }
        return result;
    }
};
