class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end()) ; 

        vector <vector <int>> ans ; 
        int n = intervals.size() ; 
        int st = intervals[0][0] ; 
        int en = intervals[0][1] ;
        for(int i = 1 ; i < n ; i++)
        {
            if (intervals[i][0] <= en && intervals[i][0] >= st) en = max(intervals[i][1] , en) ;
            else
            {   
                vector<int> temp ; 
                temp.push_back(st) ; 
                temp.push_back(en) ; 
                ans.push_back(temp) ; 
                st = intervals[i][0] ; 
                en = intervals[i][1] ; 
            }
        }
        vector<int> temp ; 
        temp.push_back(st) ; 
        temp.push_back(en) ; 
        ans.push_back(temp) ; 
        
        return ans ;  


        
    }
};
