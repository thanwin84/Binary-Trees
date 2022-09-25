// naive approach: At every node, we will calculate for left and right subtree Height to find out the longest path. If we have n nodes, at each node to calculate left
// and right subtree Height will cost O(n). So overall time complexity will be O(n^2)

//optimized approach: We can calculate diametre in the same recursion rather than calculating Height each time seperately.
// time: O(n) and space:) O(1)
class Solution {
public:
    int _max= 0;
    int solve(TreeNode * root){
        if (!root) {
            return 0;
        }
        int leftH = solve(root->left);
        int rightH = solve(root->right);
        _max = max(_max, leftH + rightH);
        return 1 + max(leftH, rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return _max;
    }
};
