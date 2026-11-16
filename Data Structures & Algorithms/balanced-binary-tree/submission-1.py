class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:

        def f(root):
            if root is None:
                return 0

            lh = f(root.left)
            rh = f(root.right)

            if lh == -1 or rh == -1:
                return -1

            if abs(lh - rh) > 1:
                return -1

            return 1 + max(lh, rh)

        return f(root) != -1