class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin() , nums.end()) ; 


        int ml = 0 ; 
        for (int x : s)
        {
            if (!s.count(x-1))
            {
                int l = 1 ; 

                while(s.count(x+1))
                {
                    x++ ; 
                    l++ ; 
                }

                ml = max(ml , l) ; 
            }
        }

        return ml ; 
    }
};
