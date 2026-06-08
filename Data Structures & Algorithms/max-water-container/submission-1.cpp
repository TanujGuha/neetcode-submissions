class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size() ; 


        int mv = 0 ; 
        for(int i = 0 ; i < n ; i++)
        {
             
            for (int j = i+1 ; j < n ; j++)
            {
                mv = max(min(heights[i] , heights[j])*(j-i) , mv) ; 
            }
        }


        return mv ;
    }
};
