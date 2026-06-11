class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int nr = grid.size() ; 
        int nc = grid[0].size() ; 

        int mx = 0 ; 

        for(int i = 0 ; i < nr ; i++)
        {
            for (int j = 0 ; j < nc ; j++)
            {
                if (grid[i][j] != 0)
                {
                    mx = max(mx , dfs(grid , i, j , 0)) ; 
                }
            }
        }


        return mx ; 
    }

    int dfs(vector<vector<int>>& grid , int x , int y , int count)
    {
        int nr = grid.size() ; 
        int nc = grid[0].size() ;      

        if (x >= nr || x < 0 || y >= nc || y < 0 || grid[x][y] == 0)
        {
            return 0 ; 
        }   
        grid[x][y] = 0 ;
        count++ ; 
        int s = dfs(grid , x+1 , y , count) ; 
        s += dfs(grid , x-1 , y , count) ;
        s += dfs(grid , x , y+1 , count)  ;
        s += dfs(grid , x , y-1 , count)  ;


        return s + 1 ; 
    }
};
