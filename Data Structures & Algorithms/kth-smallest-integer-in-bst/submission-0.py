class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:

        cnt = 0
        ans = 0

        def f(root):
            nonlocal cnt, ans

            if root is None:
                return

            f(root.left)

            cnt += 1

            if cnt == k:
                ans = root.val
                return

            f(root.right)

        f(root)
        return ans