class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int nr = board.size();
        if (nr == 0) return;
        int nc = board[0].size(); 

        vector<vector<bool>> ans(nr, vector<bool>(nc, false));

        // 1. Check Left and Right Boundaries
        for (int i = 0; i < nr; i++) {
            if (board[i][0] == 'O' && !ans[i][0]) {
                dfs(board, i, 0, ans);
            }
            if (board[i][nc - 1] == 'O' && !ans[i][nc - 1]) {
                dfs(board, i, nc - 1, ans);
            }
        }

        // 2. Check Top and Bottom Boundaries
        for (int j = 0; j < nc; j++) {
            if (board[0][j] == 'O' && !ans[0][j]) {
                dfs(board, 0, j, ans);
            }
            if (board[nr - 1][j] == 'O' && !ans[nr - 1][j]) {
                dfs(board, nr - 1, j, ans);
            }
        }

        // 3. Post-processing the entire board
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (ans[i][j] == true) {
                    // Reached from the edge, keep it as 'O'
                    board[i][j] = 'O'; 
                } else {
                    // Unreachable from edges! Trap it and capture it
                    board[i][j] = 'X';
                }
            }
        }
    }

    // Your DFS function remains exactly the same! It works perfectly.
    void dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& ans) {
        int nr = board.size();
        int nc = board[0].size();

        ans[x][y] = true; 
        if (x + 1 < nr) {
            if (board[x + 1][y] == 'O' && ans[x + 1][y] == false) {
                dfs(board, x + 1, y, ans); 
            }
        }
        if (x - 1 >= 0) {
            if (board[x - 1][y] == 'O' && ans[x - 1][y] == false) {
                dfs(board, x - 1, y, ans); 
            }
        }
        if (y + 1 < nc) {
            if (board[x][y + 1] == 'O' && ans[x][y + 1] == false) {
                dfs(board, x, y + 1, ans); 
            }
        }
        if (y - 1 >= 0) {
            if (board[x][y - 1] == 'O' && ans[x][y - 1] == false) {
                dfs(board, x, y - 1, ans); 
            }            
        }
    }
};