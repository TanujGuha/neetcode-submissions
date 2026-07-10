class Solution {
public:


    int count(vector <int> &nums , int x)
    {
        if(x < 0) return 0 ; 
        int l = 0 ; 
        int cnt = 0 ;
        int cs = 0 ; 

        int n = nums.size() ; 

        for(int r = 0 ; r < n ; r++)
        {
            cs += nums[r] ; 
            if (cs > x)
            {
                while(cs > x)
                {
                    cs -= nums[l] ; 
                    l++ ; 
                }
            }

            cnt += r - l + 1 ; 
        }

        return cnt ; 
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (count(nums , goal) - count(nums, goal-1)); 
    }
};