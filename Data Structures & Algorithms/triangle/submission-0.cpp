class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int nr = triangle.size() ; 

        for (int r = nr-2 ; r >= 0 ; r--)
        {
            for (int j = 0 ; j < triangle[r].size() ; j++)
            {
                triangle[r][j] = min(triangle[r+1][j] ,  triangle[r+1][j+1]) +  triangle[r][j]; 
            }
        }


        return triangle[0][0] ; 


    }
};