# // addLeftNodes = O(H)
# // addRightNodes = O(H)
# // addLeafNodes = O(N)
# // so overall time complexity is O(N) and space: O(H)[right subtree will take space] Note: not considering stack space in recursion call
class Solution:
    def isLeafNode(self, root):
        if not root.left and not root.right:
            return True
        return False
    def addLeftBoundary(self, root, result):
      # root node is already proccessed initially
      # trevese the left subtree excluding leaf node in the path
        current = root.left
        while current:
            if not self.isLeafNode(current):
                result.append(current.data)
            if current.left:
                current = current.left
            else:
                current = current.right
    def addLeaves(self, root, result):
       # treverse all the leaf node
        if self.isLeafNode(root):
            result.append(root.data)
            return
        if root.left: self.addLeaves(root.left, result)
        if root.right: self.addLeaves(root.right, result)
    
    def addRightBoundary(self, root, result):
      # root node is already proccessed initially
      # treverse the right subtree excluding leaf node in the path
        current = root.right
        temp = []
        while current:
            if not self.isLeafNode(current):
                temp.append(current.data)
            if current.right:
                current = current.right
            else:
                current = current.left
        while temp:
            result.append(temp.pop())
    def printBoundaryView(self, root):
        # Code here
        result = []
        if root is None:
            return result
            
        if not self.isLeafNode(root):
            result.append(root.data);
        self.addLeftBoundary(root, result)
        self.addLeaves(root, result)
        self.addRightBoundary(root, result)
        return result
