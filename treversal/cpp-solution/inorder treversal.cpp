// time: O(n) and space O(height of the tree)
// left -> root -> right
// Alorithm: Go to left -> before going to left save the current node in stack cause we need to trace back to get the root node
// stack top is the root of current subtree
// after processing root node go to right subtree
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if (root == nullptr) return inorder;
        vector<TreeNode*> stack;
        TreeNode* current = root;
        while (true){
            if (current){
                stack.push_back(current);
                // go to left subtree first
                current = current->left;
            }
            else {
                // if stack is empty, that means no need to process any node
                if (stack.size() == 0) break;
                // process the root node
                TreeNode * root_node = stack.back();
                stack.pop_back();
                inorder.push_back(root_node->val);
                // after processing root node, go to subtree
                current = root_node->right;
                
            }
            
        }
        return inorder;
    }
};
