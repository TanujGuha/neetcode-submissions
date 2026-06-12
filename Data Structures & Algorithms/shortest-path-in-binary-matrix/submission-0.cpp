class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int nr = grid.size(); 
        int nc = grid[0].size(); 

        // Edge case: If starting or ending cell is blocked, path is impossible
        if (grid[0][0] == 1 || grid[nr - 1][nc - 1] == 1) {
            return -1;
        }

        vector<vector<int>> ans(nr, vector<int>(nc, INT_MAX)); 
        queue<pair<int,int>> q; 
        
        q.push({0, 0}); 
        ans[0][0] = 1; // Path starts at length 1 (counting the starting cell)

        // Kick off BFS with initial layer size of 1, and initial distance tracking at 1
        bfs(grid, q, 1, 1, ans); 

        if (ans[nr - 1][nc - 1] == INT_MAX) {
            return -1; 
        }

        return ans[nr - 1][nc - 1]; 
    }

    void bfs(vector<vector<int>>& grid, queue<pair<int,int>> &q, int l, int dis, vector<vector<int>> &ans) {
        if (q.empty()) {
            return; 
        }

        int nr = grid.size(); 
        int nc = grid[0].size(); 
        int next_layer_size = 0;  

        // Defining the 8 possible directions (Horizontal, Vertical, and Diagonal)
        int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

        while (l--) {
            auto it = q.front(); 
            q.pop(); 
            int x = it.first; 
            int y = it.second; 

            // Explore all 8 directions independently
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // Bounds check + obstacle check + unvisited verification
                if (nx >= 0 && nx < nr && ny >= 0 && ny < nc) {
                    if (grid[nx][ny] == 0 && ans[nx][ny] == INT_MAX) {
                        ans[nx][ny] = dis + 1; // Mark distance immediately on discovery
                        q.push({nx, ny});
                        next_layer_size++;
                    }
                }
            }
        }

        // Process the next wave of elements
        bfs(grid, q, next_layer_size, dis + 1, ans); 
    }
};