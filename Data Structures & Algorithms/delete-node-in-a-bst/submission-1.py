class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:

        def helper(root):
            if root.left is None:
                return root.right

            if root.right is None:
                return root.left

            rightchild = root.right
            lastright = findlastright(root.left)

            lastright.right = rightchild
            return root.left

        def findlastright(root):
            if root.right is None:
                return root

            return findlastright(root.right)

        if root is None:
            return None

        if root.val == key:
            return helper(root)

        dummy = root

        while root is not None:
            if root.val > key:
                if root.left is not None and root.left.val == key:
                    root.left = helper(root.left)
                    break
                else:
                    root = root.left

            else:
                if root.right is not None and root.right.val == key:
                    root.right = helper(root.right)
                    break
                else:
                    root = root.right

        return dummy