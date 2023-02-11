// in postorder the last element is the root node
// suppose the current root node position is K
// so we can search the root node position in inorder array, after that we can divide the inorder array into two part
// in one part: start positon of inorder to k - 1 and in another part: k + 1 to end position of inorder
// by doing it, we are deviding the problem into sub problems.

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
