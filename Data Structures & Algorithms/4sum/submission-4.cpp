class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size() ; 
        vector <vector <int>> ans ;

        sort(nums.begin() , nums.end()) ; 

        for (int i = 0 ; i < n ; i++){
            if (i > 0)
            {
                if (nums[i] == nums[i-1]) continue ; 
            }
            for (int j = i+1 ; j < n ; j++)
            {
                if (j > i+1)
                {
                    if (nums[j] == nums[j-1]) continue ; 
                }
                
                
                int l = j+1 ; 
                int r = n-1 ; 

                while(l < r)
                {
                    long long s = 1LL*nums[i] + nums[j] + nums[l] + nums[r] ; 
                    if (s == target){
                        ans.push_back({nums[i] , nums[j] , nums[l] , nums[r]}) ; 
                        while(l+1 < n && nums[l+1] == nums[l]) l++ ;
                        while(r-1 >= 0 && nums[r-1] == nums[r]) r-- ; 

                        l++ ; 
                        r-- ; 
                    }
                    else if (s < target)
                    {
                        while(l+1 < n && nums[l+1] == nums[l])l++ ; 
                        l++ ; 
                    }
                    else if (s > target)
                    {
                        while(r-1 >= 0 && nums[r-1] == nums[r]) r-- ; 
                        r-- ; 
                    }
                }
            }

        } 

        return ans ; 
    }
};