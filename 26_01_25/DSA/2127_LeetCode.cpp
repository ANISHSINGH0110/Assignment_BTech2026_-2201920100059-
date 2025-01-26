// Approach

/*
For this problem, we can find the length of the maximum cycle in the graph. Here we only need to find the length of the largest cycle, because if there are multiple cycles, they are not connected to each other, which does not meet the problem requirements.

In addition, for the size of the cycle equal to 
2
, that is, there are two employees who like each other, then we can arrange these two employees together. If these two employees are each liked by other employees, then we only need to arrange the employees who like them next to them. If there are multiple such situations, we can arrange them all.

Therefore, the problem is actually equivalent to finding the length of the maximum cycle in the graph, and all cycles of length 
2
 plus their longest chain. The maximum of these two can be found. To find the longest chain to the cycle of length 
2
, we can use topological sorting.
The time complexity is O(n)
*/

class Solution {
public:
     int topologicalSort(vector<int>& fa) {
        int n = fa.size();
        vector<int> indeg(n);
        vector<int> dist(n, 1);
        for (int v : fa) ++indeg[v];
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            dist[fa[i]] = max(dist[fa[i]], dist[i] + 1);
            if (--indeg[fa[i]] == 0) q.push(fa[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (i == fa[fa[i]]) ans += dist[i];
        return ans;
    }
     int maxCycle(vector<int>& fa) {
        int n = fa.size();
        vector<bool> vis(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            vector<int> cycle;
            int j = i;
            while (!vis[j]) {
                cycle.push_back(j);
                vis[j] = true;
                j = fa[j];
            }
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle[k] == j) {
                    ans = max(ans, (int) cycle.size() - k);
                    break;
                }
            }
        }
        return ans;
    }
    int maximumInvitations(vector<int>& favorite) {
        return max(maxCycle(favorite), topologicalSort(favorite));
    }
};