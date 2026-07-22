class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis,
             int &vertices, int &degreeSum) {
        vis[u] = true;
        vertices++;
        degreeSum += adj[u].size();

        for (int v : adj[u]) {
            if (!vis[v])
                dfs(v, adj, vis, vertices, degreeSum);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int vertices = 0;
                int degreeSum = 0;

                dfs(i, adj, vis, vertices, degreeSum);

                int edgeCount = degreeSum / 2;

                if (edgeCount == vertices * (vertices - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};