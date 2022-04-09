class Solution:
    def __init__(self):
        self.result = float('-inf')
    def solve(self, root):
        if root is None:
            return 0
        # negative value will naver help to  to increase sum
        left = max(0, self.solve(root.left))
        right = max(0, self.solve(root.right))
        # taking curve path
        self.result = max(self.result, root.val + left + right)
        # taking left or right path
        return root.val + max(left, right)
        
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.solve(root)
        return self.result
        
