class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0 ; 
        int j = 0 ; 

        vector <vector<int>> res ; 
        while(i < firstList.size() && j < secondList.size())
        {
            int stm = max(firstList[i][0] , secondList[j][0]) ; 
            int edm = min(firstList[i][1] , secondList[j][1]) ; 

            if(stm <= edm)
            {
                res.push_back({stm , edm}) ; 
            }

            if (firstList[i][1] < secondList[j][1])
            {
                i++ ; 
            }
            else
            {
                j++ ; 
            }
        }

        return res ; 
    }
};