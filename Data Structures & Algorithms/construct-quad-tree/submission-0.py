class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':

        def isallsame(grid, x, y, n):
            val = grid[x][y]

            for i in range(x, x + n):
                for j in range(y, y + n):
                    if grid[i][j] != val:
                        return False

            return True

        def f(grid, x, y, n):

            if isallsame(grid, x, y, n):
                return Node(grid[x][y], True)

            half = n // 2

            topLeft = f(grid, x, y, half)
            topRight = f(grid, x, y + half, half)
            bottomLeft = f(grid, x + half, y, half)
            bottomRight = f(grid, x + half, y + half, half)

            return Node(
                True,
                False,
                topLeft,
                topRight,
                bottomLeft,
                bottomRight
            )

        return f(grid, 0, 0, len(grid))