/*
The task is to find the largest possible island size in a grid by converting at most one 0 to 1. Here's a step-by-step approach used in the provided code:

A direction vector dir is defined to facilitate movement in the grid in four directions: up, right, down, and left.
Movement in a direction is calculated using (newX, newY) = (x + dir[i], y + dir[i + 1]).

isValid(int& n, int x, int y)
This function checks whether a cell (x, y) lies within the grid bounds.

markIsland(vector<vector<int>>& grid, int& island_number, int& n, int x, int y)
This recursive DFS function marks all cells of the current island with a unique island_number and returns the total size of the island.

Traverse the entire grid. For each unvisited land cell (grid[x][y] == 1), start a DFS using markIsland() to:

Assign a unique island_number to all connected land cells.
Calculate the size of the island and store it in island_size[island_number].

Iterate over all cells of the grid again:

If the cell is 0, simulate flipping it to 1.
Collect the unique neighboring islands by checking in all four directions and storing them in a set<int> islands.
Sum the sizes of these neighboring islands and add 1 for the converted 0 itself.
Keep track of the largest possible island size.

If the entire grid is already filled with 1s, return n * n.
If no valid flip is possible, the maximum size remains 0.

Time Complexity: O(N^2)

*/

class Solution {
    vector<int> dir = {-1, 0, 1, 0, -1};

    bool isValid(int& n, int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    int markIsland(vector<vector<int>>& grid, int& island_number, int& n, int x, int y) {
        grid[x][y] = island_number;
        int count = 1;

        for (int i = 0; i < 4; ++i) {
            int newX = x + dir[i];
            int newY = y + dir[i + 1];

            if (isValid(n, newX, newY) && grid[newX][newY] == 1) {
                count += markIsland(grid, island_number, n, newX, newY);
            }
        }

        return count;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> island_size;
        int island_number = 2;

        // Mark islands
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == 1) {
                    int island = markIsland(grid, island_number, n, x, y);
                    island_size[island_number] = island;
                    island_number++;
                }
            }
        }

        // Try to convert each 0 to 1 one by one
        int max_size = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] == 0) {
                    set<int> islands;
                    for (int i = 0; i < 4; ++i) {
                        int newX = x + dir[i];
                        int newY = y + dir[i + 1];

                        if (isValid(n, newX, newY)) {
                            islands.insert(grid[newX][newY]);
                        }
                    }

                    // Iterate and find total size of current island
                    int curr_island = 1;
                    for (int key : islands) {
                        curr_island += island_size[key];
                    }

                    max_size = max(max_size, curr_island);
                }
            }
        }

        return max_size == 0 ? n * n : max_size;
    }
};