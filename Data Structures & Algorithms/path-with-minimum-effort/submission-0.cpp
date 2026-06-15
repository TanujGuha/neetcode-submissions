class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size() ; 
        int c = heights[0].size() ; 

        vector <vector <int>> ans(r, vector <int> (c , INT_MAX)) ;
        ans[0][0] = 0 ; 

     
        priority_queue<pair<int , pair<int,int>> , vector <pair<int , pair<int,int>>> , greater <pair<int , pair<int,int>>>> pq ; 
        pq.push({0 , {0,0}}) ; 

        while(!pq.empty())
        {
            auto it = pq.top() ; 
            pq.pop() ; 
            int effort = it.first ; 
            int x = it.second.first ; 
            int y = it.second.second ; 

            if (effort > ans[x][y]) continue;

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];
 
                if (!((nx < r && nx >= 0) &&(ny < c && ny >= 0))) continue ; 

                int jump = abs(heights[nx][ny] - heights[x][y]) ; 
                int mx = max(effort ,jump) ; 

                if (ans[nx][ny] > mx)
                {
                    ans[nx][ny] = mx ; 
                    pq.push({ans[nx][ny] , {nx  , ny}}) ; 
                }
            }    

            
        }

        return ans[r-1][c-1] ;
    }
};