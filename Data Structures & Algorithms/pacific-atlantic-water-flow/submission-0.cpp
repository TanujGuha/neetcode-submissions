#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int nr = heights.size(); 
        int nc = heights[0].size(); 

        // 2D boolean matrices to track which cells can reach each ocean
        vector<vector<bool>> pac(nr, vector<bool>(nc, false));
        vector<vector<bool>> atla(nr, vector<bool>(nc, false));

        // 1. Run DFS for Top and Bottom rows
        for (int i = 0; i < nc; i++) {
            dfs(heights, 0, i, pac);       // Top row (Pacific)
            dfs(heights, nr - 1, i, atla); // Bottom row (Atlantic)
        }

        // 2. Run DFS for Left and Right columns
        for (int i = 0; i < nr; i++) {
            dfs(heights, i, 0, pac);       // Left col (Pacific)
            dfs(heights, i, nc - 1, atla); // Right col (Atlantic)
        }

        // 3. Collect all coordinates where both oceans are reachable
        vector<vector<int>> result;
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (pac[i][j] && atla[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result; 
    }

private:
    // We only need one clean unified DFS function by passing the respective visited map
    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& visited) {
        // Mark current cell as reachable
        visited[x][y] = true; 

        int nr = heights.size(); 
        int nc = heights[0].size();         
        
        // Directions arrays for elegant 4-way exploration
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Bounds check
            if (nx >= 0 && nx < nr && ny >= 0 && ny < nc) {
                // Critical checks:
                // 1. Must NOT have been visited yet (prevents infinite cycles)
                // 2. Neighbor height must be greater than or equal to current height (climbing uphill)
                if (!visited[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    dfs(heights, nx, ny, visited);
                }
            }
        }
    }
};