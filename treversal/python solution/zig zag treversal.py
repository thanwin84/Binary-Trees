# time: O(n) and space: O(n)
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        if root is None:
            return result
        evenLevel= []
        oddLevel = []
        oddLevel.append(root)
        while evenLevel or oddLevel:
            currentLevel = []
            current = None
            # in the next level(even level) we need to treverse from right to left
            # so in this level if we push left node first, at the end we will end up 
            # with right node on top of the stack
            while oddLevel:
                current = oddLevel.pop()
                currentLevel.append(current.val)
                if current.left:
                    evenLevel.append(current.left)
                if current.right:
                    evenLevel.append(current.right)
            if currentLevel:
                result.append(currentLevel)
            currentLevel = []
            while evenLevel:
                current = evenLevel.pop()
                currentLevel.append(current.val)
                if current.right:
                    oddLevel.append(current.right)
                if current.left:
                    oddLevel.append(current.left)
            if currentLevel:
                result.append(currentLevel)
        return result
                
