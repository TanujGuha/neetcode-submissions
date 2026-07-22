class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // vector <pair <int,int>> cpy ;
        // for (int i = 0 ; i < nums2.size() ; i++)
        // {
        //     cpy.push_back({nums2[i]  i}) ; 
        // } 

        // sort(cpy.begin() , cpy.end()) ; 


        vector <int> ans ;
        for (int i : nums1)
        {
            
            auto it = find(nums2.begin() , nums2.end() , i) - nums2.begin() ; 
            bool pull = false ;
            for (int j = it ; j < nums2.size() ; j++)
            {
                if (nums2[j] > nums2[it])
                {
                    pull = true ; 
                    ans.push_back(nums2[j]) ; 
                    break ; 
                }
            }
            if (!pull) ans.push_back(-1) ; 
        }

        return ans; 

    }
};