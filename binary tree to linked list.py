class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root is None:
            return
        temp = None
        if root.right:
            # store right subtree in temp
            temp = root.right
        if root.left:
            # set root's right subtree to root's left subtree
            root.right = root.left
            current = root.left
            # find the right most node
            while current.right:
                current = current.right
            # set right most node to temp
            current.right = temp
            # make root's left to  point to None
            root.left = None
        
        self.flatten(root.left)
        self.flatten(root.right)
        
