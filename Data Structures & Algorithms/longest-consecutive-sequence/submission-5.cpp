class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0 ; 
    
        unordered_set<int> us ; 
        for (int x : nums) us.insert(x) ; 

        int ans = 1 ; 
        int l = 1 ; 

        for (int i = 0 ; i < nums.size() ; i++)
        {
            if (us.count(nums[i]-1)) continue ; 
            else
            {   
                int x = nums[i] ; 
                while(us.count(x+1))
                {
                    x++ ; 
                    l++ ; 
                }

            }

            ans = max(ans , l) ; 
            l = 1 ; 
        }
        return ans ;

    }
};
