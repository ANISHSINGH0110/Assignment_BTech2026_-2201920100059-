/*
The task is to find the number of provinces (connected components) in a graph where isConnected[i][j] = 1 indicates 
that city i is directly connected to city j, and 0 indicates no direct connection. A province is a group of directly or indirectly connected cities.

The input matrix isConnected is an adjacency matrix representation of an undirected graph.
If isConnected[i][j] == 1, there is an edge between nodes i and j.
The dfs function is used to explore all nodes connected to the current node.
Mark the current node as visited (visited[curr] = true).
Recursively visit all adjacent nodes (j) that are connected and have not been visited.
Initialize a visited vector to keep track of visited nodes.
Initialize a provinces counter to store the number of connected components.
Traverse each node (i):
If a node is not visited, it marks the start of a new province.
Call the DFS function to explore all nodes in this connected component.
Increment the provinces counter after a full DFS traversal.
Return the total number of provinces.


*/

class Solution {
public:
    void dfs(int curr,vector<vector<int>>&isConnected,vector<bool>&visited)
    {
        visited[curr] = true;
        for(int j=0;j<isConnected.size();j++)
        {
            if(isConnected[curr][j] && !visited[j])
              dfs(j,isConnected,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(),false);
        int provinces = 0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!visited[i])
            {
                dfs(i,isConnected,visited);
                provinces++;
            }
        }
        return provinces;
    }
};