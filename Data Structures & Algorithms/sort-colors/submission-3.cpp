class Solution {
public:


    void sorter(int n1, int m1 , vector <int> & nums){
        int n = nums.size() ;
        int l , r ; 
        for (int i = 0 ; i < n ;i++)
        {
            if (nums[i] == m1)
            {
                l = i ; 
                break ;
            }
        }
        for (int i = n-1 ; i >= 0 ; i--)
        {
            if (nums[i] == n1)
            {
                r = i ; 
                break ;
            }
        }

        while(l <= r)
        {
            swap(nums[l] , nums[r]) ;
            l++ ; 
            r-- ; 

            while(l < n && nums[l] != m1)
            {
                l++  ;
            }
            while(r >= 0 && nums[r] != n1)
            {
                r-- ; 
            }
            if (l == n || r == -1)
            {
                break ;
            }
        }

        return ;
    }
    void sortColors(vector<int>& nums) {
        int l , r ; 
        int n = nums.size() ; 
        sorter(0 , 1 , nums) ; 
        sorter(0 , 2 , nums) ; 
        sorter(1 , 2 , nums) ; 

        return  ; 



    }
};