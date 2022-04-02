# time: O(n) and space: O(H of the tree)
# left subtree -> right subtree -> process the root node 
# using one stack
class Solution:
    def postorderTraversal(self, root):
        postorder = []
        if root is None:
            return postorder
        stack = []
        current = root
        while current or stack:
            # if current is not null, push it to the stack and move left
            # cause we have to go left first, then right and then root
            if current:
                stack.append(current)
                current = current.left
            else:
                # if current becomes null, that means we aleady treversed left subtree, now we have to check right subtree
                # if stack top right is null, that means we have no right subtree to check
                # we can process the root, STACK TOP IS THE ROOT NODE OF CURRENT SUBTREE
                # after that, we will check again if popped item is the right subtree of stack top
                # if popped item is right subtree stack top, cause we have go to root node after right subtree
                # we print root
                temp = stack[-1].right
                if temp is None:
                    temp = stack[-1]
                    stack.pop()
                    postorder.append(temp.val)
                    while stack and temp == stack[-1].right:
                        temp = stack[-1]
                        stack.pop()
                        postorder.append(temp.val)
                else:
                    # if temp is not null, that means we have to check right subtree
                    current = temp
        return postorder
