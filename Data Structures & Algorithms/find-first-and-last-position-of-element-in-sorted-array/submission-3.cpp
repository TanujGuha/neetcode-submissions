class Solution {
public:

    int binh(vector<int>& nums, int target, int st , int en)
    {
        int l = st ; 
        int r = en ; 

        while(l <= r)
        {
            int m = (l + r)/2 ; 
            if (nums[m] == target)
            {
                if (m+1 == nums.size())
                {
                    return m ; 
                }
                else if (m+1 < nums.size())
                {
                    if (nums[m+1] != target) return m ; 
                    else l = m+1 ; 
                }
                
            }
            else if(nums[m] < target)
            {
                l = m+1 ;
            }
            else
            {
                r = m-1 ; 
            }
        }

        return -1 ;
    }
    int binl(vector<int>& nums, int target, int st , int en)
    {
        int l = st ; 
        int r = en ; 

        while(l <= r)
        {
            int m = (l + r)/2 ; 
            if (nums[m] == target)
            {
                if (m-1 == -1)
                {
                    return m ; 
                }
                else if (m-1 > -1)
                {
                    if (nums[m-1] != target) return m ; 
                    else r = m-1 ; 
                }
                
            }
            else if(nums[m] < target)
            {
                l = m+1 ;
            }
            else
            {
                r = m-1 ; 
            }
        }

        return -1;  
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans ; 
        if (nums.empty())
        {
            ans.push_back(-1) ; 
            ans.push_back(-1) ; 
            return ans; 
        }
        
        int n = nums.size()-1 ;
        ans.push_back(binl(nums , target , 0 , n)) ;
        ans.push_back(binh(nums , target , 0 , n)) ;

        return ans ; 
    }
};