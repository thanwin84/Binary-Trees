// time and space: O(n).
// using two stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> s1;
        vector<int> result;
        if (!root){
            return result;
        }
        s1.push_back(root);
        while (s1.size() > 0){
            TreeNode * current = s1.back();
            s1.pop_back();
            result.push_back(current->val);
            if (current->left) s1.push_back(current->left);
            if (current->right) s1.push_back(current->right);
        }
      // post order is stored at reverse order
      // so we need to reverse it
        reverse(result.begin(), result.end());
        return result;
    }
};
