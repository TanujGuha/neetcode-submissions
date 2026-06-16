class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int r = grid.size() ; 
        int c = grid[0].size() ; 


        vector <vector<int>> dist(r , vector <int> (c,INT_MAX)) ; 
        dist[0][0] = grid[0][0] ; 

        

        priority_queue< pair<int , pair<int,int>> , vector < pair< int , pair<int,int>>> , greater < pair<int , pair<int,int>>> > pq ; 
        
        pq.push({grid[0][0] , {0,0}}) ; 

        while(!pq.empty())
        {
            auto it = pq.top() ;
            pq.pop() ; 

            int cost = it.first ; 
            int x    = it.second.first ; 
            int y    = it.second.second ; 

            int dr[4] = {-1 , 1 , 0 , 0 } ; 
            int dc[4] = {0 , 0 , -1 , 1 } ; 
            for (int i = 0 ; i <  4; i++)
            {
                int nx = x + dr[i] ; 
                int ny = y + dc[i] ; 

                if (nx < r && nx >= 0 && ny < c && ny >= 0){
                    if (dist[nx][ny] > max(cost , grid[nx][ny])) 
                    {
                        dist[nx][ny] = max(cost , grid[nx][ny]) ; 
                        pq.push({dist[nx][ny] , {nx , ny}}) ; 
                    }

                } 
            }
        }


        return dist[r-1][c-1] ; 


    }
};
