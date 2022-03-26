// time: o(n) and O(height of the tree)
// inspired from recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root){
            return result;
        }
        TreeNode * current = root;
        vector<TreeNode*> stack;
        while (true){
            if (current){
                stack.push_back(current);
                current = current->left;
            }
            else {
                if (stack.size() == 0){
                    break;
                }
                TreeNode * topNode = stack.back();
                stack.pop_back();
                result.push_back(topNode->val);
                current = topNode->right;
            }
        }
        return result;
    }
};
