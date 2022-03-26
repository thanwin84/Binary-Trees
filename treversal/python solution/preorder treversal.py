# time: O(n) and space: O(height of the tree)
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        if root is None:
            return result
        stack = []
        stack.append(root)
        while stack:
            current = stack.pop()
            result.append(current.val)
            # pushing the right first, coz we need print the left tree first
            if current.right:
                stack.append(current.right)
            if current.left:
                stack.append(current.left)
        return result
