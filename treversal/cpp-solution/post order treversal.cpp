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

// using single stack
// time: O(n) and space: O(H of the tree)
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (!root){
            return postorder;
        }
        TreeNode * current = root;
        vector<TreeNode*> stack;
        while (current || stack.size() > 0){
            if (current){
                stack.push_back(current);
                current = current->left;
            }
            else {
                TreeNode * temp = stack.back()->right;
                if (!temp){
                    temp = stack.back();
                    stack.pop_back();
                    postorder.push_back(temp->val);
                    while (stack.size() > 0 && temp == stack.back()->right){
                        temp = stack.back();
                        stack.pop_back();
                        postorder.push_back(temp->val);
                    }
                }
                else {
                    current = temp;
                }
            }
        }
        return postorder;
    }
};
