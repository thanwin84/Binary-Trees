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

class Solution {
public:
    TreeNode *solve(vector<int>&preorder, int upperBound, int &currentInd){
        if (currentInd == preorder.size() || preorder[currentInd] >upperBound){
            return nullptr;
        }
        TreeNode * root = new TreeNode(preorder[currentInd++]);
        // left values must be lesser than upperbound
        root->left = solve(preorder, root->val, currentInd);
        // right values must be greater than upperbound
        root->right = solve(preorder, upperBound, currentInd);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int currentInd = 0;
        return solve(preorder, INT_MAX, currentInd);
    }
};
