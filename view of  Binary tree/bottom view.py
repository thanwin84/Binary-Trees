# time: O(nlong) and space: O(n)
from collections import deque
class Solution:
    def bottomView(self, root):
        result = []
        if root is None:
            return result
        q = deque()
        current = root
        lookup = {}
        line = 0
        q.append([current, line])
        while q:
            levelSize = len(q)
            for cur in range(levelSize):
                leftNode = q.popleft()
                current = leftNode[0]
                line = leftNode[1]
                lookup[line] = current.data
                if current.left:
                    q.append([current.left, line - 1])
                if current.right:
                    q.append([current.right, line + 1])
        for key, value in sorted(lookup.items()):
            result.append(value)
        return result
