class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        total = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(1,n):
            grid[0][i] += grid[0][i-1]
        for i in range(1,m):
            grid[i][0] += grid[i-1][0]
        for i in range(1,m):
            for j in range(1,n):
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]
        total = grid[m-1][n-1]
        if total&1:
            return False
        total>>=1
        idx = bisect_left(grid[-1],total)
        if grid[-1][idx]==total:
            return True
        idx = bisect_left(list(row[-1] for row in grid), total)
        return grid[idx][-1]==total