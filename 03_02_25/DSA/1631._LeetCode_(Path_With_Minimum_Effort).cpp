/*
Given a 2D grid heights, the task is to find a path from the top-left cell (0, 0) to the bottom-right cell (row-1, col-1) such that the maximum effort required between adjacent cells along the path is minimized.

Effort between two adjacent cells (x1, y1) and (x2, y2) is defined as:
effort=∣heights[x1][y1]−heights[x2][y2]∣
The objective is to minimize the maximum absolute height difference between any two adjacent cells along the chosen path.

The priority queue stores nodes as {effort, {x, y}}, where:
effort: the current minimum effort to reach cell (x, y).
(x, y): the coordinates of the cell.
Stores the minimum possible effort required to reach each cell.
Initialized to INT_MAX, except for the starting cell (0, 0).
Start from (0, 0) with effort = 0.
Explore all possible movements (up, down, left, right).
Calculate the effort to move to the adjacent cell.
newMaxDiff=max(currEffort,∣heights[x][y]−heights[newX][newY]∣)
Update dist[newX][newY] if newMaxDiff is smaller and push the node to the priority queue.
If we reach the destination (row-1, col-1), return the dist value.

Time Complexity: O(N⋅log(N))
Where N=row×col. 
Dijkstra's algorithm with a priority queue efficiently handles the shortest path computation.
*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; //min heap

        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0] = 0; //dijestra logic

        while(!pq.empty())
        {
            pair<int,pair<int,int>>frontNode = pq.top();
            pq.pop();
            int currAbsDiff = frontNode.first;
            int x = frontNode.second.first;
            int y = frontNode.second.second;
            if(x == row-1 && y == col-1)
              return dist[x][y];
            else // then do up,down,left,right movement
            {
                int dx[] = {0,-1,0,1};
                int dy[] = {-1,0,1,0};
                for(int i=0;i<4;i++)
                {
                    int newX = x+dx[i];
                    int newY = y+dy[i];
                    if(newX >= 0 && newY >= 0 && newX < row && newY < col)//if new coordinate are safe
                    {
                        int newAbsDiff = abs(heights[x][y]-heights[newX][newY]);
                        int newMaxDiff = max(currAbsDiff,newAbsDiff);
                        if(newMaxDiff < dist[newX][newY])
                        {
                            dist[newX][newY] = newMaxDiff;
                            pq.push({newMaxDiff,{newX,newY}});
                        }
                    }
                }
            }  
        }
        return 0;
    }
};