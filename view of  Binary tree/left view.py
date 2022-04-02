# using BFS
# Time: O(n) 
# space: q size will be at max n /2 so space complexity is O(n)
from collections import deque
def LeftView(root):
    
    # code here
    leftNodes = []
    if root is None:
        return leftNodes
    q = deque()
    current = root
    q.append(current)
    while q:
        levelSize = len(q)
        leftNodes.append(q[0].data)
        for curr in range(levelSize):
            current = q.popleft()
            if current.left:
                q.append(current.left)
            if current.right:
                q.append(current.right)
    return leftNodes
