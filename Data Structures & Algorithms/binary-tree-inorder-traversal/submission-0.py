class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []

        def f(root):
            if root is None:
                return

            f(root.left)
            ans.append(root.val)
            f(root.right)

        f(root)
        return ans