# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        q = deque()
        q.append([root, 0])
        _maxWidth = 1

        while q:
            levelSize = len(q)
            first = second = 0
            for i in range(levelSize):
                current = q.popleft()
                if i == 0: 
                    first = current[1]
                if i == levelSize - 1:
                    last = current[1]
                if current[0].left:
                    q.append([current[0].left, 2 * current[1] + 1])
                
                if current[0].right:
                    q.append([current[0].right, 2 * current[1] + 2])

            temp = last - first + 1
            _maxWidth = max(_maxWidth, temp)
        return _maxWidth
