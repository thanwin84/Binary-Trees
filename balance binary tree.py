# time: O(n) and O(1) if we not considering stack space
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        flag = True
        def solve(root):
            nonlocal flag
            if root is None:
                return 0
            left = solve(root.left)
            right = solve(root.right)
            if abs(left - right) > 1:
                flag = False
            return 1 + max(left, right)
        solve(root)
        return flag
