class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowCondition, vector<vector<int>>& colCondition) {
        // --- 1. ROW TOPO SORT ---
        // Changed graph structure sizes to k + 1 to safely handle 1-indexed values
        vector<vector<int>> row(k + 1); 
        for (int i = 0; i < rowCondition.size(); i++) {
            auto it = rowCondition[i];
            row[it[0]].push_back(it[1]);  
        }

        vector<int> id(k + 1, 0);
        for (int i = 1; i <= k; i++) {
            for (auto it : row[i]) {
                id[it]++; 
            }
        }

        queue<int> q; 
        for (int i = 1; i <= k; i++) {
            if (id[i] == 0) {
                q.push(i); 
            }
        }

        vector<int> rm; 
        while (!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            rm.push_back(it); 

            for (auto i : row[it]) {
                id[i]--; 
                if (id[i] == 0) {
                    q.push(i);
                }
            }
        }

        // Cycle check: if we couldn't sort all k elements, a cycle exists
        if (rm.size() != k) {
            return {}; 
        }

        // --- 2. COLUMN TOPO SORT ---
        vector<vector<int>> col(k + 1); 
        // Fixed: Using the correct condition array size
        for (int i = 0; i < colCondition.size(); i++) {
            auto it = colCondition[i];
            col[it[0]].push_back(it[1]);  
        }

        vector<int> id1(k + 1, 0);
        for (int i = 1; i <= k; i++) {
            for (auto it : col[i]) {
                id1[it]++; 
            }
        }

        queue<int> q1; 
        for (int i = 1; i <= k; i++) {
            if (id1[i] == 0) {
                q1.push(i); 
            }
        }

        vector<int> cm; 
        while (!q1.empty()) {
            auto it = q1.front(); 
            q1.pop(); 
            cm.push_back(it); 

            for (auto i : col[it]) {
                id1[i]--; 
                if (id1[i] == 0) {
                    q1.push(i);
                }
            }
        }

        if (cm.size() != k) {
            return {}; 
        }

        // --- 3. OPTIMIZED MATRIX ASSEMBLY ---
        // Instead of searching arrays over and over, map value coordinates directly
        vector<int> row_pos(k + 1);
        vector<int> col_pos(k + 1);

        for (int j = 0; j < k; j++) {
            row_pos[rm[j]] = j; // Number rm[j] sits at row index j
            col_pos[cm[j]] = j; // Number cm[j] sits at column index j
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++) {
            ans[row_pos[i]][col_pos[i]] = i;
        }

        return ans;
    }
};