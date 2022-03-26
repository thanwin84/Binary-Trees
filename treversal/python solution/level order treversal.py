#  time: O(n)
# space: in the worst case the q size will be n/2. so space complexity will be O(n)
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        if root is None:
            return result
        q = deque()
        q.append(root)
        while q:
            levelSize = len(q)
            currentLevel = []
            # this will  make sure that we loop level by level
            for i in range(levelSize):
                currentNode = q.popleft()
                currentLevel.append(currentNode.val)
                if currentNode.left:
                    q.append(currentNode.left)
                if currentNode.right:
                    q.append(currentNode.right)
            # after we finised current loop, we already populated q with next level nodes
            result.append(currentLevel)
        return result
