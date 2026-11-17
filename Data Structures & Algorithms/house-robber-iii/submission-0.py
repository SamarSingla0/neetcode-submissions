# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        

        def f(root):
            if not root:
                return [0, 0]

            lh = f(root.left)
            rh = f(root.right)

            withroot = root.val + lh[1] + rh[1]
            withoutroot = max(lh) + max(rh)
            return [withroot, withoutroot]

        return max(f(root))