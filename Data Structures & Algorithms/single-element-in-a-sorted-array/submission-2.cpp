class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); 

        // Handle boundaries outside the loop to avoid out-of-bounds errors
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];

        // Safe search space since edges are already checked
        int l = 1; 
        int r = n - 2;

        while (l <= r) {
            int m = l + (r - l) / 2; // Protect against integer overflow

            // Safe to check neighbors now because m is strictly between 1 and n-2
            if (nums[m-1] != nums[m] && nums[m] != nums[m+1]) {
                return nums[m];
            }

            if (m % 2 != 0) { // Odd index
                if (nums[m-1] == nums[m]) {
                    l = m + 1; 
                } else {
                    r = m - 1;
                }
            } 
            else { // Even index
                if (nums[m] == nums[m+1]) {
                    l = m + 1; 
                } else {
                    r = m - 1; 
                }
            }
        }

        return -1; 
    }
};