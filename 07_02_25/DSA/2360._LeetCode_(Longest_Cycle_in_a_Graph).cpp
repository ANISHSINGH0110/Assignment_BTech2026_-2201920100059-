/*
Traverses nodes using depth-first search (DFS).
Maintains multiple tracking structures to detect cycles and calculate their lengths.
visited: Tracks if a node was already visited to avoid redundant exploration.
dfsTracker: Tracks the current DFS path to detect back edges indicating a cycle.
dist: Stores the length of the path from the starting node to each visited node.
longestCycleLength: Stores the length of the longest detected cycle.
Start DFS from the current node.
Mark the node as visited and part of the DFS path.
If the next node is already part of the current DFS path (dfsTracker[nextNode] == true), a cycle is detected.
Reset the dfsTracker for the current node to clean up after the DFS recursion.
Iterate over all nodes to ensure each connected component is explored
If no cycle is detected, return -1; otherwise, return the length of the longest cycle.
*/
class Solution {
public:
    void dfs(int node,vector<int>&edges,vector<bool>& visited,vector<bool>& dfsTracker,vector<int>& dist,int currLength,int &longestCycleLength)
    {
        if(node == -1)
          return;
        visited[node] = true;
        dfsTracker[node] = true;
        dist[node] = currLength;
        int nextNode = edges[node];
        if(nextNode != -1)
        {
            if(!visited[nextNode])
              dfs(nextNode,edges,visited,dfsTracker,dist,currLength+1,longestCycleLength);
            else if(dfsTracker[nextNode]) //cycle is there
            {
                int cycleLength = currLength-dist[nextNode]+1;
                longestCycleLength = max(longestCycleLength,cycleLength);
            }  
        }  
        dfsTracker[node] = false; //backtrack;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool>visited(n,0);
        vector<bool>dfsTracker(n,0);
        vector<int>dist(n,0);
        int longestCycleLength = -1;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
              dfs(i,edges,visited,dfsTracker,dist,0,longestCycleLength);
        }
        return longestCycleLength;
    }
};