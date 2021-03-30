from collections import deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isCompleteTree(self, root: TreeNode):
        flag = False
        q = deque()
        q.append(root)
        while q:
            node = q.popleft()
            if node is None:
                flag = True
                continue
            if flag:
                return False
            q.append(node.left)
            q.append(node.right)
        return True



node1 = TreeNode(1)
node1.left = TreeNode(2)
node1.right = TreeNode(3)
node1.left.left = TreeNode(4)
node1.right.left = TreeNode(6)
ob = Solution()
print(ob.isCompleteTree(node1))
