# using BFS
# Time: O(n) 
# space: q size will be at max n /2 so space complexity is O(n)

# with preorder recursion
# but here we treverse right subtree first, then right
#  time: O(n) and space: O(H of binary Tree)
class Solution:
    
    def solve(self, root, level, result):
        if root is None:
            return result
        if len(result) == level:
            result.append(root.val)
        self.solve(root.right, level + 1, result)
        self.solve(root.left, level + 1, result)
        return result
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        return self.solve(root, 0, [])
        
