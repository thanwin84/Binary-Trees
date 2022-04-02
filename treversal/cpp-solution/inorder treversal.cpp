// time: O(n) and space O(height of the tree)
// left -> root -> right
// Alorithm: Go to left -> before going to left save the current node in stack cause we need to trace back to get the root node
// stack top is the root of current subtree
// after processing root node go to right subtree
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
