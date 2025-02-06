/*
This problem can be modeled as a weighted directed graph problem where:

Each variable represents a node.
The given equation u/v = value becomes a directed edge between u and v with a weight of value.
The inverse relationship v/u = 1.0 / value becomes another edge in the opposite direction.
The task is to compute the division result for given queries or return -1.0 if the division is impossible.

This problem can be modeled as a weighted directed graph problem where:

Each variable represents a node.
The given equation u/v = value becomes a directed edge between u and v with a weight of value.
The inverse relationship v/u = 1.0 / value becomes another edge in the opposite direction.
The task is to compute the division result for given queries or return -1.0 if the division is impossible.

DFS is used to explore possible paths between two nodes and calculate the cumulative product along each path.
Parameters:

adj: The graph representation.
src, dst: Current and target nodes for the query.
visited: Tracks visited nodes to prevent cycles.
product: Cumulative product along the path.
ans: Stores the final result.
Base cases:

If src == dst, set ans = product.
Skip already visited nodes.

Disconnected Components: Return -1.0 if either src or dst is not present in the graph.
Self-division: If src == dst, return 1.0.
Unreachable Destination: If no path exists, return -1.0.
Division by non-existent variables: Handle gracefully by checking node presence in the adjacency list.

Graph Construction: O(N)
*/
class Solution {
public:
     void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string src, string dst, unordered_set<string>& visited, double product, double &ans) {
        if(visited.find(src) != visited.end())
            return;
        
        visited.insert(src);
        if(src == dst) {
            ans = product;
            return;
        }
        
        for(auto p : adj[src]) {
            
            string v   = p.first;
            double val = p.second;
            
            dfs(adj, v, dst, visited, product*val, ans);
                
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        
        unordered_map<string, vector<pair<string, double>>> adj;
        
        for(int i = 0; i<n; i++) {
            
            string u   = equations[i][0];
            string v   = equations[i][1];
            double val = values[i];
            
            adj[u].push_back({v, val});        //To handle a/c
            adj[v].push_back({u, 1.0/val});    //To handle c/a
        }
        
        vector<double> result;
        
        for(auto &query : queries) {
            
            string src = query[0];
            string dst = query[1];
            
            double ans     = -1.0;
            double product = 1.0;
            
            
            if(adj.find(src) != adj.end()) {
                unordered_set<string> visited;
                
                dfs(adj, src, dst, visited, product, ans);
                
            }
            
            result.push_back(ans);
            
        }
        
        return result;
    }
};