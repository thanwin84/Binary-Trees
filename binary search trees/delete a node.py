# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minValueFromRightSubtree(self, root):
        if root is None:
            return -1
        if root.left is None:
            return root.val
        return self.minValueFromRightSubtree(root.left)

    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return root
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            # case 1: no child 
            if root.left == None and root.right == None:
                del root
                root = None
            # case 2: one child
            elif root.left is None:
                temp = root.right
                del root
                root = temp
            elif root.right is None:
                temp = root.left
                del root
                root = temp
            else:
                minValue = self.minValueFromRightSubtree(root.right)
                root.val = minValue
                root.right = self.deleteNode(root.right, minValue)
        return root
