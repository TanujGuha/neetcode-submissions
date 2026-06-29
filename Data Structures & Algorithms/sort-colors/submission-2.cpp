class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() ; 
        int zer = count(nums.begin() , nums.end() , 0) ;
        int one = count(nums.begin() , nums.end() , 1) ; 
        int two = n - zer - one ; 


        int j = 0 ; 

        for (int i = 0 ; i < n && j < zer ; i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[i] , nums[j]) ; 
                j++ ;
            }
        }

        j = zer  ; 
        for(int i = j ; i < n ; i++)
        {
            if(nums[i] == 1)
            {
                swap(nums[i] , nums[j]) ; 
                j++ ; 
            }
        }

        return  ;

    }
};