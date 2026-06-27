class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); 

        int can1 , can2 ;
        int c1 = 0 , c2 = 0; 


        for (int i = 0 ; i < n ; i++)
        {
            if (nums[i] == can1)
            {
                c1++ ; 
            }  
            else if (nums[i] == can2)
            {
                c2++ ; 
            }

            else if (c1 == 0)
            {
                can1 = nums[i] ;
                c1++ ; 
            }
            else if (c2 == 0)
            {
                can2 = nums[i] ;
                c2++ ; 
            }
            else 
            {
                c1-- ;
                c2-- ; 
            }
        }

        c1 = 0 ; 
        c2 = 0 ; 

        for (int i = 0 ; i < n ; i++)
        {
            if (nums[i] == can1)
            {
                c1++ ; 
            }
            else if (nums[i] == can2)
            {
                c2++ ; 
            }
        }

        vector <int> ans ; 

        if (c1 > n/3)
        {
            ans.push_back(can1) ; 
        }
        if (c2 > n/3)
        {
            ans.push_back(can2) ; 
        }

        if(!ans.empty())
        {
            sort(ans.begin() , ans.end()) ; 
            return ans ;
        }
        return ans; 
    }    

};