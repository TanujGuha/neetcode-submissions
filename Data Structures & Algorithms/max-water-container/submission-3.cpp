class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size() ;
        int l = 0 ; 
        int r = n-1 ; 


        int mx = 0 ; 
        while(l < r)
        {
            mx = max(mx , min(heights[l] ,heights[r]) * (r - l)) ;
            if (heights[l] < heights[r])
            {
                l++ ; 
            }
            else
            {
                r-- ; 
            }

        }
        return mx ; 
    }
};
