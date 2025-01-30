/*
//Approach 
The problem requires calculating the number of "magnificent sets" for a given undirected graph where 
the vertices are partitioned based on certain criteria related to graph properties.

Use an adjacency list (unordered_map<int, vector<int>> graph) to represent the graph from the given edges.
For every edge edge[i] = [u, v], create a bidirectional mapping between u and v.

A helper function isBipartite() is used to check whether each component of the graph is bipartite.
Use Breadth-First Search (BFS) and color the nodes using two colors 0 and 1.
If any adjacent nodes share the same color, the component is not bipartite, and the answer becomes -1.
Maintain an unordered_map<int, int> color to track colors assigned to the nodes.

Traverse all the nodes using a BFS loop to identify and isolate connected components.
Use an unordered_set<int> visited to track nodes that have already been visited.
For each component, store its nodes in a component vector.

For each node in the connected component:
Perform two BFS traversals:
First BFS from the current node to find the farthest node (farthestNode).
Second BFS starting from this farthest node to calculate the diameter of the component.
The diameter of the component is the longest path between any two nodes in that component.

For each component, calculate the maximum possible diameter (localMax) and add it to the total count of "magnificent sets."

Time Complexity: O(N+E)
BFS is performed for each node and edge, ensuring linear time complexity in terms of nodes and edges.

*/


class Solution {
public:
    bool isBipartite(int node, unordered_map<int, vector<int>>& graph, unordered_map<int, int>& color) {
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int neighbor : graph[curr]) {
                if (color.count(neighbor)) {
                    if (color[neighbor] == color[curr]) return false;
                } else {
                    color[neighbor] = 1 - color[curr];
                    q.push(neighbor);
                }
            }
        }
        return true;
    }
    pair<int, int> bfs(int start, unordered_map<int, vector<int>>& graph) {
        queue<int> q;
        unordered_map<int, int> dist;
        q.push(start);
        dist[start] = 0;
        int farthestNode = start, maxDist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : graph[node]) {
                if (!dist.count(neighbor)) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > maxDist) {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }
        return {farthestNode, maxDist};
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> color;
        unordered_set<int> visited;
        int maxGroups = 0;

        for (int i = 1; i <= n; ++i) {
            if (!visited.count(i)) {
                if (!isBipartite(i, graph, color)) return -1;
                queue<int> q;
                vector<int> component;
                q.push(i);
                visited.insert(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
                    for (int neighbor : graph[node]) {
                        if (!visited.count(neighbor)) {
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
                int localMax = 0;
                for (int node : component) {
                    int farthest = bfs(node, graph).first;
                    int diameter = bfs(farthest, graph).second + 1;
                    localMax = max(localMax, diameter);
                }
                maxGroups += localMax;
            }
        }
        return maxGroups;
    }
};