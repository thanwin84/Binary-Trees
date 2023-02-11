/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// from preorder, we will get the root
// inorder: left > root > right
// so if we track the root node in inorder array, we can devide the array into two parts. In one part: inorderstart to (root position - 1)
// and in another part (root position + 1) to inorder end
// by doing this we break the problem into sub problem
class Solution {
public:
    TreeNode * solve(vector<int> &preorder, vector<int> &inorder, int &preorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int > &inorderMap){
        if (preorderIndex >= inorder.size() || inorderStart > inorderEnd){
            return nullptr;
        }
        // the first node of preorder is always the root node
        TreeNode * root = new TreeNode(preorder[preorderIndex++]);
        int rootIndex = inorderMap[root->val]; 
        root->left = solve(preorder, inorder, preorderIndex, inorderStart, rootIndex - 1, inorderMap);
        root->right = solve(preorder, inorder, preorderIndex, rootIndex + 1, inorderEnd, inorderMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int > inorderMap;
        for (int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        int preorderIndex = 0;
        return solve(preorder, inorder, preorderIndex, 0, inorder.size() -1, inorderMap);

    }
};
