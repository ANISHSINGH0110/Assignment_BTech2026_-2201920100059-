//Approach
/*
The given problem can be solved using Depth First Search (DFS) to explore and count fish in connected grid components, 
treating each non-zero grid cell as a potential starting point for a region.

The dfs() function recursively explores the grid to find the number of fish in a connected component.
Base conditions:
Return 0 if the current cell is out of bounds (i < 0, i >= grid.size(), j < 0, j >= grid[0].size()).
Return 0 if the current cell is 0 (either already visited or has no fish).

Key operations:
Store the fish count of the current cell (caughtFish = grid[i][j]).
Mark the cell as visited by setting grid[i][j] = 0.
Recursively explore its four adjacent neighbors:
dfs(grid, i + 1, j) (down)
dfs(grid, i - 1, j) (up)
dfs(grid, i, j + 1) (right)
dfs(grid, i, j - 1) (left)
Return the sum of caughtFish and the results from recursive DFS calls.

Function findMaxFish():

Initialize ans to store the maximum fish caught across all connected regions.
Iterate over each cell in the grid (i, j):
If grid[i][j] > 0, perform a DFS starting from this cell to compute the total fish count in that region.
Update ans with the maximum value between ans and the result of dfs(grid, i, j).

Time Complexity: O(m×n)
*/



class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
        return 0;
        if (grid[i][j] == 0)
        return 0;
        int caughtFish = grid[i][j];
        grid[i][j] = 0;                                     // Mark 0 as visited
        return caughtFish +                                 //
            dfs(grid, i + 1, j) + dfs(grid, i - 1, j) +  //
            dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
  }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); ++i)
        for (int j = 0; j < grid[0].size(); ++j)
            if (grid[i][j] > 0)
            ans = max(ans, dfs(grid, i, j));

        return ans;
    }
};