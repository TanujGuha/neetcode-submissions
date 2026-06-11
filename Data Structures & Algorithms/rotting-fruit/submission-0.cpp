#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nr = grid.size(); 
        int nc = grid[0].size(); 

        queue<pair<int,int>> q; 
        int good = 0; 
        
        for(int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); // Changed .insert() to .push()
                }
                else if (grid[i][j] == 1) {
                    good++; 
                }
            }
        }   

        // Edge Case: If there are no fresh oranges, no time is needed.
        if (good == 0) return 0;

        // Pass good by reference so our helper can decrement it
        int time = bfs(q, q.size(), grid, good); 

        // If fresh fruits are left over, return -1
        return (good == 0) ? time : -1;
    }

    // Changed return type of neigh to int to match your code, and added good tracking
    int bfs(queue<pair<int,int>> &q, int len, vector<vector<int>>& grid, int &good) {
        // Base case: if no more fruits are left to expand, or we're out of options
        if (q.empty()) {
            return 0; 
        }

        int nl = 0; // Tracks how many fruits turn rotten in the NEXT layer
        while (len > 0) {
            // C++ queue pop mechanics
            auto it = q.front(); 
            q.pop(); 
            len--; 
            
            int x = it.first; 
            int y = it.second; 

            // Corrected function spelling to match definition
            nl += neigh(x + 1, y, q, grid, good);
            nl += neigh(x - 1, y, q, grid, good);
            nl += neigh(x, y + 1, q, grid, good);
            nl += neigh(x, y - 1, q, grid, good);
        }

        // Only count this minute if this wave actually successfully infected something
        if (nl > 0) {
            return 1 + bfs(q, nl, grid, good);
        }
        
        return 0;
    }

    // Changed return type to int to match the usage in the main loop
    int neigh(int x, int y, queue<pair<int,int>> &q, vector<vector<int>>& grid, int &good) {
        int nr = grid.size(); 
        int nc = grid[0].size(); 

        // Boundary checks
        if (x >= nr || x < 0 || y >= nc || y < 0) {
            return 0; 
        }   
        
        // We only care about fresh fruits (1). 
        // If it's empty (0) or already rotten (2), skip it.
        if (grid[x][y] != 1) {
            return 0; 
        }

        // Rot the fruit
        grid[x][y] = 2; 
        good--; // Decrement overall fresh count
        q.push({x, y});   
        
        return 1;  
    }
};