/*
This solution identifies critical connections (bridges) in an undirected connected graph using DFS traversal and Tarjan's Algorithm.

A bridge in a graph is an edge whose removal disconnects the graph into two or more components. The task is to find all such bridges in the given graph.
Key Concepts
DFS Traversal:
The algorithm performs a depth-first search to explore all nodes and maintain information for identifying bridges.

Discovery Time (tin) and Lowest Time (low):

tin[src]: Time when the node src is visited for the first time.
low[src]: Earliest visited node reachable from node src (via its subtree).
Bridge Condition:
If low[nbr] > tin[src], the edge between src and nbr is a bridge.
We build an adjacency list for efficient graph representation.
The DFS function countBridges() is called with initial parameters, starting from src = 0.
Increment the timer for discovery and update tin and low for the current node.
Traverse neighbors:

If the neighbor is the parent, skip it.
If the neighbor is unvisited, recursively explore and update low[src] based on low[nbr].
If true, add the edge as a bridge to ans.

Time Complexity: O(V+E)
Each node and edge are visited exactly once during DFS.
*/
class Solution {
public:
    void countBridges(int src,int parent,vector<int>&tin,vector<int>&low,unordered_map<int,bool>&vis,int timer,
                       vector<vector<int>>&ans,unordered_map<int,list<int>>&adj)
     {
        timer++;
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        //neighbour pe travel krte hai
        for(auto nbr:adj[src])
        {   //kyuki undirectrd graph hai toh neighbour mai parent bhii ho skta hai
            if(nbr == parent) continue;
            else if(!vis[nbr])
            {  //normal travel kro and check for bridge
              countBridges(nbr,src,tin,low,vis,timer,ans,adj);
              low[src] = min(low[src],low[nbr]);//aye mai bhul jata hu
              //do bridge check
              if(low[nbr] > tin[src])
              {
                //bridge exist
                vector<int>temp;
                temp.push_back(src);
                temp.push_back(nbr);
                ans.push_back(temp);
              }
            }
            else
            {  //already visited and not parent
                //low time ko update if possible
                low[src] = min(low[src],low[nbr]);
            }
        }
      }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;
        int timer = 0;
        int src = 0;
        int parent = -1;
        vector<int>tin(n);
        vector<int>low(n);
        unordered_map<int,bool>vis;
        unordered_map<int,list<int>>adj;
        for(auto i:connections)
        {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        countBridges(src,parent,tin,low,vis,timer,ans,adj);
        return ans;
    }
};