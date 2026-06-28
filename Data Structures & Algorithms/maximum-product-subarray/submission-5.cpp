class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        // FIXED: Initialize variables with the first element instead of 1
        int max_p = nums[0]; 
        int min_p = nums[0]; 
        int ans = nums[0];
        
        int n = nums.size();

        // Start iterating from the second element (index 1)
        for (int i = 1; i < n; i++)
        {
            int pdt = nums[i];
            
            if (pdt < 0) swap(max_p, min_p); 

            max_p = max(pdt, max_p * pdt); 
            min_p = min(pdt, min_p * pdt); 

            ans = max(ans, max_p); 
        } 

        return ans; 
    }
};