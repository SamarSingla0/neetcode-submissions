# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:

        def f(root):
            if root is None: return 0

            lh = f(root.left)
            rh = f(root.right)

            return 1 + max(lh, rh)

        ans = f(root)
        return ans