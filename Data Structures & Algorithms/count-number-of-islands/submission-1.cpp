class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size() ; 
        int nc = grid[0].size() ; 


        char ss = 'a' ; 
        int color = 0 ; 
        for(int i = 0 ; i < nr ; i++)
        {
            for(int j = 0 ; j < nc ; j++)
            {
                if (grid[i][j] != '1'&& grid[i][j] != '0')
                {
                    continue ; 
                }
                if (grid[i][j] == '1')
                {
                    dfs(grid , i , j , ss) ; 
                    color++ ;  
                    ss++ ;                   
                }
            }
        }

        return color ; 
    }



    void dfs(vector<vector<char>>& grid , int x , int y , char color)
    {
        int nr = grid.size() ; 
        int nc = grid[0].size() ; 

        if (x >= nr || x < 0 || y >= nc || y < 0 || grid[x][y] == '0')
        {
            return ; 
        }
        if (grid[x][y] == '1')
        {
            grid[x][y] = color ; 
            dfs(grid , x+1 , y , color) ; 
            dfs(grid , x-1 , y , color) ; 
            dfs(grid , x , y+1 , color) ; 
            dfs(grid , x , y-1 , color) ; 
        }
        
    }
};
