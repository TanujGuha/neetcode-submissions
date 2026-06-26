class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate ; 
        int count = 0 ; 

        for (int i : nums)
        {
            if (!count)
            {
                count =  1 ; 
                candidate = i ; 
            }
            else{
                if (i == candidate)
                {
                    count++ ; 
                }
                else
                {
                    count-- ; 
                }
            }
        }

        return candidate; 
    }
};