class Solution {
public:


    // multi source BFS problem, sources are the treasure spots
    // any bfs requires a queue
    // need to keep track of neighbours added in the next layer, for their processeing
    // also need to keep a runnning score board of the times it took the BFS to reach that block
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int nr = grid.size() ;
        int nc = grid[0].size() ;

        queue <pair<int,int>> q ; 
        for (int i = 0 ; i < nr ; i++)
        {
            for (int j = 0 ; j < nc ; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({i,j}) ; 
                }
            }
        }

        int l = q.size() ; 
        int d = 0 ; 

        vector <vector<int>> ans(nr , vector<int>(nc, 2147483647)) ; 
        bfs(grid , q , l , ans , d) ; 

        // while(!q.empty())
        // {
        //     int na = bfs(grid , q , l , ans , d) ; 
        //     bfs()
        // }


        for(int i = 0 ; i < nr ; i++)
        {
            for (int j = 0 ; j < nc ; j++)
            {
                if (grid[i][j] == 2147483647)
                {
                    grid[i][j] = min(grid[i][j] , ans[i][j]) ; 
                }
            }
        }
    }


    void bfs(vector<vector<int>>& grid , queue<pair<int,int>> &q , int l  ,vector <vector<int>> &ans , int dis)
    {

        int nr = grid.size() ;
        int nc = grid[0].size() ;

        if (q.empty())
        {
            return  ;
        }


        int na = 0 ; 
        while(l--)
        {
            auto ele = q.front() ;
            q.pop() ; 


            int x = ele.first ; 
            int y = ele.second ; 

            if (x+1 < nr)
            {
                if (grid[x+1][y] == 2147483647 && ans[x+1][y] == 2147483647)
                {
                    q.push({x+1 , y}) ; 
                    ans[x+1][y] = dis+1 ;
                    na++ ;
                }
            }
            if (x-1 >= 0)
            {
                if (grid[x-1][y] == 2147483647 && ans[x-1][y] == 2147483647)
                {
                    q.push({x-1 , y}) ; 
                    ans[x-1][y] = dis+1 ; 
                    na++ ; 
                }                
            }
            if (y+1 <nc)
            {
                if(grid[x][y+1] == 2147483647 && ans[x][y+1] == 2147483647)
                {
                    q.push({x , y+1}) ; 
                    ans[x][y+1] = dis + 1 ; 
                    na++ ; 
                }
            }
            if (y-1 >= 0)
            {
                if (grid[x][y-1] == 2147483647 && ans[x][y-1] == 2147483647)
                {
                    q.push({x , y-1}) ; 
                    ans[x][y-1] = dis + 1 ;
                    na++ ; 
                }
            }
        }

        dis++;
        bfs(grid, q , na , ans , dis) ; 

    }
};
