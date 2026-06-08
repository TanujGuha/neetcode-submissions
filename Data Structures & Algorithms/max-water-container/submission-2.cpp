class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size() ; 


        int mv = 0 ; 
        int l = 0 ;
        int r = n-1 ; 

        while(l < r)
        {
            mv = max(mv, (r-l)*min(heights[l] , heights[r])) ; 
            if (heights[l] <= heights[r])
            {
                l++ ; 
            }
            else{
                r-- ; 
            }
        }


        return mv ;
    }
};
