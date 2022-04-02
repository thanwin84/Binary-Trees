# time: O(n) and space O(height of the tree)
# left -> root -> right
# Alorithm: Go to left -> before going to left save the current node in stack cause we need to trace back to get the root node ->stack top is the root of current subtree
# after processing root node go to right subtree
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
                # stack top: root of the CURRENT subtree
                topNode = stack.pop()
                result.append(topNode.val)
                current = topNode.right
        return result
