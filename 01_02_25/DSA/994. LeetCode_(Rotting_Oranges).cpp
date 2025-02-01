/*
The problem is to find the minimum number of minutes required to turn all fresh oranges into rotten oranges in a grid, where:

0: empty cell
1: fresh orange
2: rotten orange
A rotten orange can rot its adjacent fresh oranges in 4 directions (up, down, left, right) per minute.

Get the grid dimensions rows and cols.
Create a queue q to perform Breadth-First Search (BFS).
Initialize a counter freshOranges to keep track of the number of fresh oranges.
Traverse the grid:
If the current cell contains a rotten orange (2), add it to the queue.
If the current cell contains a fresh orange (1), increment freshOranges.
If there are no fresh oranges initially, return 0 as no time is needed.
Perform BFS while the queue is not empty:
For each level, process all rotten oranges in the queue.
Check adjacent cells using direction vectors {{0,1}, {1,0}, {0,-1}, {-1,0}}.
If an adjacent cell contains a fresh orange, rot it (grid[newRow][newCol] = 2), decrement freshOranges, and add it to the queue for the next BFS level.
If any new oranges rot during the current level, increment minutes.
If any fresh oranges remain (freshOranges > 0), return -1.
Otherwise, return the minutes.

Time Complexity: O(n×m)
Each cell is visited once when processing the queue.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int rows = grid.size(),cols = grid[0].size();
      queue<pair<int,int>>q;
      int freshOranges = 0;

      //1 all the rotten oranges to the queue
      for(int i=0;i<rows;i++)
      {
        for(int j=0;j<cols;j++)
        {
            if(grid[i][j] == 2)
              q.push({i,j});
            else if(grid[i][j] == 1)
              freshOranges++;  
        }
      }  

      if(!freshOranges)
         return 0;
      int minutes = 0;
      vector<pair<int,int>>directions = {{0,1},{1,0},{0,-1},{-1,0}};
      //perform bfs
      while(!q.empty())
      {
            int size = q.size();
            bool hasRottenNew  = false;
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                for(auto dir: directions)
                {
                    int newRow = curr.first+dir.first;
                    int newCol = curr.second+dir.second;
                    if(newRow>=0 && newRow < rows //if adj cell is a fresh
                        && newCol >=0 && newCol <cols
                        && grid[newRow][newCol] == 1)
                    {
                        grid[newRow][newCol] = 2;
                        freshOranges--;
                        q.push({newRow,newCol});//for next level
                        hasRottenNew = true;
                    }    
                }
            }
            if(hasRottenNew)
              minutes++; 
      }  
       if(freshOranges > 0)
         return -1;
       return minutes;  

    }
};