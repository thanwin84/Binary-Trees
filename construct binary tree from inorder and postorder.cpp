class Solution {
public:
    TreeNode * solve(vector<int> &postorder, vector<int> &inorder, int &postorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int > &inorderMap){
        if (postorderIndex < 0 || inorderStart > inorderEnd){
            return nullptr;
        }
        // the first node of preorder is always the root node
        TreeNode * root = new TreeNode(postorder[postorderIndex--]);
        int rootIndex = inorderMap[root->val]; 
        
        root->right = solve(postorder, inorder, postorderIndex, rootIndex + 1, inorderEnd, inorderMap);
        root->left = solve(postorder, inorder, postorderIndex, inorderStart, rootIndex - 1, inorderMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int > inorderMap;
        for (int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        int postorderIndex = inorder.size() - 1;
        return solve(postorder, inorder, postorderIndex, 0, inorder.size() -1, inorderMap);

    }
};
