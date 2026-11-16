# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []

        def f(root):
            if root is None:
                return

            f(root.left)
            f(root.right)
            ans.append(root.val)
        
        f(root)
        return ans