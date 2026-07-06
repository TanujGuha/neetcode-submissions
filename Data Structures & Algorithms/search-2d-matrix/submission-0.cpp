class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size()*matrix[0].size() ; 
                //   rows    *  columns
        int rows = matrix.size() ; 
        int col = matrix[0].size() ;  
        int l = 0 ; 
        int r = n-1 ; 

        while(l <= r)
        {
            int m = (l+r)/2 ; 

            int rr = m / col ;
            int cr = m % col ; 

            if (matrix[rr][cr] == target) return true ; 
            if(matrix[rr][cr] < target) l = m + 1 ; 
            else r = m-1; 
        }
        return false ; 
    }
};
