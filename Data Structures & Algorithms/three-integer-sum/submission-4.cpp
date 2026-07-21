class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort(nums.begin() , nums.end()) ; 
        // vector <vector <int>> ans;  

        int n = nums.size() ;
        int target = 0 ;
        set <vector<int>> ans ; 
        for (int i = 0 ; i < n ; i++)
        {

            int tar1 = target - nums[i] ; 
            for (int j = i+1 ; j < n ; j++)
            {
                for (int k= j+1 ; k < n ; k++)
                {
                    // if(nums[j] == nums[k]) continue ;
                    int s = nums[j] + nums[k] ; 
                    if (s == tar1) {
                        vector<int> temp = {nums[i] , nums[j] , nums[k]} ; 
                        sort(temp.begin() , temp.end()) ;
                        ans.insert(temp) ; 
                    }
                }
            }
        }

        vector <vector<int>> a ; 
        for (auto it = ans.begin() ; it != ans.end() ; it++)
        {
            a.push_back(*it) ; 
        }

        return a ; 
    }
};
