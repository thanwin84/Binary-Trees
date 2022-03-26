# time: O(n) and space O(height of the tree)
# inspired from recursion
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        if root is None:
            return result
        stack = []
        current = root
        while True:
            if current:
                stack.append(current)
                current = current.left
            else:
                if not stack:
                    break
                topNode = stack.pop()
                result.append(topNode.val)
                current = topNode.right
        return result
