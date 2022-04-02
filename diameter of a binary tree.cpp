// naive approach: At every node, we will calculate for left and right subtree Height to find out the longest path. If we have n nodes, at each node to calculate left
// and right subtree Height will cost O(n). So overall time complexity will be O(n^2)

//optimized approach: We can calculate diametre in the same recursion rather than calculating Height each time seperately.
// time: O(n) and space:) O(1)
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int result = 0;
    int solve(Node *root){
        if (!root){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        int temp = 1 + left + right;
        result = max(result, temp);
        return 1 + max(left, right);
    }
    int diameter(Node*root){
        solve(root);
        return result;
    }
};
