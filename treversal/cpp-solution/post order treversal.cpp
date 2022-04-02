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
                // if current is not null, push it to the stack and move left
                // cause we have to go left first, then right and then root
                stack.push_back(current);
                current = current->left;
            }
            else {
                // if current becomes null, that means we aleady treversed left subtree, now we have to check right subtree
                // if stack top right is null, that means we have no right subtree to check
                // we can process the root, STACK TOP IS THE ROOT NODE OF CURRENT SUBTREE
                // after that, we will check again if popped item is the right subtree of stack top
                // if popped item is right subtree stack top, cause we have go to root node after right subtree
                // we print root
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
