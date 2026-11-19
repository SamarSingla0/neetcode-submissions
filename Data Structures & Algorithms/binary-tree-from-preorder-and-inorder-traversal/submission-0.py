class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:

        inMap = {}

        for i in range(len(inorder)):
            inMap[inorder[i]] = i

        def f(preStart, preEnd, inStart, inEnd):

            if preStart > preEnd or inStart > inEnd:
                return None

            root = TreeNode(preorder[preStart])

            inRoot = inMap[root.val]
            numsLeft = inRoot - inStart

            root.left = f(
                preStart + 1,
                preStart + numsLeft,
                inStart,
                inRoot - 1
            )

            root.right = f(
                preStart + numsLeft + 1,
                preEnd,
                inRoot + 1,
                inEnd
            )

            return root

        return f(0, len(preorder) - 1, 0, len(inorder) - 1)