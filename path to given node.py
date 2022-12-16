class Solution:
    # @param A : root node of tree
    # @param B : integer
    # @return a list of integers
    def __init__(self):
        self.path = []
    def helper(self, A, B):
        if A is None:
            return False
        self.path.append(A.val)
        if A.val == B:
            return True
        left = self.helper(A.left, B)
        right = self.helper(A.right, B)
        if left or right:
            return True
        self.path.pop()
        return False
    def solve(self, A, B):
        if A is None:
            return self.path
        self.helper(A, B)
        return self.path
