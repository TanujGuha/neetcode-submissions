class Solution {
public:
    int fP(int u, vector<int> &parent) {
        if (u == parent[u]) return u;
        return parent[u] = fP(parent[u], parent);
    }

    int ur(int u, int v, vector<int> &parent, vector<int> &rank) {
        int up = fP(u, parent);
        int vp = fP(v, parent);

        if (up == vp) return 0;

        int ru = rank[up];
        int rv = rank[vp];

        if (ru < rv) parent[up] = vp;
        else if (ru > rv) parent[vp] = up;
        else {
            parent[up] = vp;
            rank[vp]++;
        }
        return 1;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // 1. Save original indices before sorting
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i); 
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        // 2. Find the baseline MST weight
        vector<int> base_vis(n);
        vector<int> base_rank(n, 0);
        for (int i = 0; i < n; i++) base_vis[i] = i;

        int base_mst = 0;
        int base_edges = 0;
        for (auto &edge : edges) {
            if (ur(edge[0], edge[1], base_vis, base_rank)) {
                base_mst += edge[2];
                base_edges++;
            }
        }

        vector<int> critical;
        vector<int> pseudoCritical;

        // 3. Test every edge
        for (int i = 0; i < edges.size(); i++) {
            
            // --- EXCLUSION TEST (Is it Critical?) ---
            vector<int> ex_vis(n);
            vector<int> ex_rank(n, 0);
            for (int k = 0; k < n; k++) ex_vis[k] = k; // Fresh DSU reset

            int ex_wt = 0;
            int ex_edges = 0;
            for (int j = 0; j < edges.size(); j++) {
                if (i == j) continue; // Skip current edge
                if (ur(edges[j][0], edges[j][1], ex_vis, ex_rank)) {
                    ex_wt += edges[j][2];
                    ex_edges++;
                }
            }

            // If graph disconnects or weight increases, it's CRITICAL
            if (ex_edges < n - 1 || ex_wt > base_mst) {
                critical.push_back(edges[i][3]); // Push original index
                continue; // An edge cannot be both critical and pseudo-critical
            }

            // --- INCLUSION TEST (Is it Pseudo-Critical?) ---
            vector<int> in_vis(n);
            vector<int> in_rank(n, 0);
            for (int k = 0; k < n; k++) in_vis[k] = k; // Fresh DSU reset

            // Force include the current edge first
            ur(edges[i][0], edges[i][1], in_vis, in_rank);
            int in_wt = edges[i][2];
            int in_edges = 1;

            for (int j = 0; j < edges.size(); j++) {
                if (i == j) continue;
                if (ur(edges[j][0], edges[j][1], in_vis, in_rank)) {
                    in_wt += edges[j][2];
                    in_edges++;
                }
            }

            // If it can form a valid MST with the same base weight, it's PSEUDO-CRITICAL
            if (in_edges == n - 1 && in_wt == base_mst) {
                pseudoCritical.push_back(edges[i][3]); // Push original index
            }
        }

    
       return {critical, pseudoCritical};
    }
};