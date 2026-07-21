class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = (int)numbers.size() ; 
        int l = 0 ; 
        int r = n-1 ; 


        vector <int> ans ; 
        while(l < r)
        {
            int s = numbers[l] +  numbers[r] ; 
            if (s == target) {
                ans.push_back(l+1) ; 
                ans.push_back(r+1) ; 
                return ans;  
            }
            else if (s < target)
            {
                int prev = numbers[l] ; 
                while(numbers[l] == prev)
                {
                    l++ ; 
                }
            }
            else {
                int prev = numbers[r] ; 
                while(numbers[r] == prev){
                    r-- ; 
                }
            }
        }

        return ans;  
    }
};
