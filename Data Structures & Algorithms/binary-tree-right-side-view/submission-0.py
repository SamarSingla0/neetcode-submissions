class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []

        def f(root, level):
            if root is None:
                return

            if level == len(ans):
                ans.append(root.val)

            f(root.right, level + 1)
            f(root.left, level + 1)

        f(root, 0)
        return ans