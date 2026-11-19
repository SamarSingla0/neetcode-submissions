class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxi = float('-inf')

        def f(root):
            nonlocal maxi

            if root is None:
                return 0

            lh = max(0, f(root.left))
            rh = max(0, f(root.right))

            maxi = max(maxi, lh + rh + root.val)

            return root.val + max(lh, rh)

        f(root)
        return maxi