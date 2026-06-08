class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n  = nums.size() ; 

        if (n == 0)
        {
            return 0 ; 
        }
        set <int> s ;

        for(int i = 0 ; i < n ; i++)
        {
            s.insert(nums[i]) ;
        }


        int ml = 1 ; 
        for (auto it : s)
        {
            if(s.count(it-1) == 0)
            {
                int x = it ; 
                int l  = 0 ; 
                while(s.count(x))
                {
                    x++ ; 
                    l++ ; 
                }

                ml = max(ml , l ) ; 
            }
        }

        return ml ; 
    }
};
