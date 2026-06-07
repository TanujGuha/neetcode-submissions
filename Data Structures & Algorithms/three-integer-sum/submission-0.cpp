class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ; 

        vector <vector <int>> ans ; 
        int n = nums.size() ; 
        
        for (int i = 0 ; i < n ; i++)
        {
            // Fix 3A: Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int v = -nums[i] ; 
            int l = i+1 ; 
            int r = n-1 ;

            while(l < r)
            {
                if (nums[l] + nums[r] > v)
                {
                    r-- ; 
                }
                else if (nums[l] + nums[r] < v)
                {
                    l++ ; 
                }
                else 
                {
                    // Fix 1 & 2: Push the actual values directly into ans, don't break!
                    ans.push_back({nums[i], nums[l], nums[r]});
                    
                    // Fix 3B: Skip duplicates for 'l' and 'r' inside the window
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    
                    // Move pointers past the elements we just processed
                    l++ ; 
                    r-- ; 
                }
            }
        }
        
        return ans; // Don't forget to return the final vector!
    }
};