# using level order treversal with line technique
# time: O(nlogn) and space: O(n)
from collections import  deque
class Solution:
    # Function to return a list of nodes visible from the top view
    # from left to right in Binary Tree.
    def topView(self, root):
        result = []
        if root is None:
            return result
        q = deque()
        lookup = {}
        current = root
        line = 0
        q.append([current, line])
        while q:
            levelSize = len(q)
            for cur in range(levelSize):
                pair = q.popleft()
                current = pair[0]
                line = pair[1]
                if line not in lookup:
                    lookup[line] = current.data
                if current.left:
                    q.append([current.left, line -1])
                if current.right:
                    q.append([current.right, line + 1])
        for key, value in sorted(lookup.items()):
            result.append(value)
        return result
