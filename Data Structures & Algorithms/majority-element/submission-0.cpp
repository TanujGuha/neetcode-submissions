class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int> mpp ; 
       for(int i : nums)
       {
            mpp[i]++ ; 
       }

       for (auto [num , freq] : mpp)
       { 
            if (freq > nums.size()/2) return num ; 
       }
    }
};