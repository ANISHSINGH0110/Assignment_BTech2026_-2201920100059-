/*
The task is to determine whether all rooms can be visited starting from room 0.
Each room contains keys to other rooms represented by an adjacency list rooms, where rooms[i] holds the keys accessible from room i.

Use a Depth-First Search (DFS) to explore the rooms starting from room 0.

Mark the current room as visited (seen[node] = true).
For each key found in the current room, recursively visit the connected room if it hasn't been visited.
Use a vector<bool> seen to keep track of whether a room has been visited.

The recursive dfs() function:
Marks the current room as visited.
Recursively visits unvisited rooms accessible via the current room's keys.

After the DFS traversal, use ranges::all_of to check whether all rooms have been visited.

Time Complexity: O(N+E)
Where 
N is the number of rooms, and 
E is the total number of keys across rooms.
*/
class Solution {
public:
    void dfs(const vector<vector<int>>& rooms, int node, vector<bool>& seen) {
        seen[node] = true;
        for (const int child : rooms[node])
        if (!seen[child])
            dfs(rooms, child, seen);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> seen(rooms.size());
        dfs(rooms, 0, seen);
        return ranges::all_of(seen, [](int s) { return s == true; });
    }
};