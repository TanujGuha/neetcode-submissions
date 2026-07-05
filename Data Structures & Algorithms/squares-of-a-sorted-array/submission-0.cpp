class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size() ; 
        int l = 0 ; 
        int r = n-1; 

        vector <int> ans ; 

        while(l <= r)
        {
            if (abs(nums[l]) < abs(nums[r]))
            {
                ans.push_back(abs(nums[r])*abs(nums[r])); 
                r--;
            }
            else
            {
                ans.push_back(abs(nums[l])*abs(nums[l])); 
                l++ ;
            }
        }

        reverse(ans.begin() , ans.end()) ; 

        return ans ; 
    }
};