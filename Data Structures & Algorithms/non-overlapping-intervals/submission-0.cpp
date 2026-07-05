class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end()) ; 
        int end = intervals[0][1] ; 
        int n = intervals.size() ; 
        int cnt = 0 ; 
        for (int i = 1 ; i < n ; i++)
        {
            if (end <= intervals[i][0]) 
            {
                end = intervals[i][1] ;
            }
            else
            {
                end = min(end , intervals[i][1]) ; 
                cnt++ ; 
            }
        }

        return cnt ;
    }
};
