class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size() ; 
        vector <int> front(n) ,  back(n) ; 
        front[0] = nums[0] ; 
        back[n-1] = nums[n-1] ; 
        for (int i = 1 ; i < n ; i++)
        {
            front[i] = front[i-1]* nums[ i] ; 
        }
        for (int i = n-2 ; i >= 0 ; i--)
        {
            back[i] = back[i+1]*nums[i] ; 
        }        

        vector <int> ans(n) ;
        for (int i = 0 ; i < n ; i++)
        {
            int left ; 
            if (i-1 < 0) left = 1 ; 
            else left = front[i-1] ; 

            int right ;
            if (i+1 >= n) right = 1 ; 
            else right = back[i+1] ; 


            ans[i] = left*right ; 
        }

        return ans ; 
    }
};
