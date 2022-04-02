# naive approach: At every node, we will calculate for left and right subtree Height to find out the longest path. If we have n nodes, at each node to calculate left
#  and right subtree Height will cost O(n). So overall time complexity will be O(n^2)

# optimized approach: We can calculate diametre in the same recursion rather than calculating Height each time seperately.
#  time: O(n) and space:) O(1)
class Solution:
    
    #Function to return the diameter of a Binary Tree.
    def diameter(self,root):
        # Code here
        result = 0
        def helper(root):
            nonlocal result
            if root is None:
                return 0
            left = helper(root.left)
            right = helper(root.right)
            result = max(result, 1 + left + right)
            return 1 + max(left, right)
        helper(root)
        return result
