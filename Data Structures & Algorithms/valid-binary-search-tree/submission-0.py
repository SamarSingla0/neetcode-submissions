# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        def f(node, left,  right):
            if not node: 
                return True

            if not(node.val < right and node.val > left):
                return False

            return (f(node.left, left, node.val) and
            f(node.right, node.val, right))

        return f(root, float("-inf"), float("inf"))