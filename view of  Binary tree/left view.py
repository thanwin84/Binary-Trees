# same as right view
def solve(root, level, result):
    if root is None:
        return result
    if level == len(result):
        result.append(root.data)
    solve(root.left, level + 1, result)
    solve(root.right, level + 1, result)
    return result
def LeftView(root):
    return solve(root, 0, [])
