class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ; 


        vector <vector <int>> ans ;
        for (int i = 0 ; i < n ; i++)
        {
            if (i > 0)
            {
                if (nums[i] == nums[i-1]) continue ; 
            }

            int l = i+1 ; 
            int r = n-1 ;

            while(l < r)
            {
                vector <int> temp ; 
                int s = nums[i] + nums[l] + nums[r] ; 
                if (s == 0)
                {   
                    temp.push_back(nums[i]) ; 
                    temp.push_back(nums[l]) ; 
                    temp.push_back(nums[r]) ; 
                    ans.push_back(temp) ; 
                    while(l+1 < n && nums[l+1] == nums[l]) l++ ; 
                    l++ ; 
                    while(r-1 >= 0 && nums[r-1] == nums[r]) r-- ; 
                    r-- ; 
                }
                if (s < 0)
                {
                    while(l+1 < n && nums[l+1] == nums[l]) l++ ; 
                    l++ ; 
                }
                if (s > 0)
                {
                    while(r-1 >= 0 && nums[r-1] ==  nums[r]) r-- ; 
                    r-- ; 
                }

                
            }
        }
        return ans ; 
    }
};
