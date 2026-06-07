class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       

       int n = numbers.size() ; 
       int i = 0 ; 
       int j = n-1 ; 

       vector <int> v(2) ; 

       while(i < j)
       {
            if (numbers[i] + numbers[j] > target )
            {
                j-- ; 
            }
            else if(numbers[i] + numbers[j] < target )
            {
                i++ ; 
            }
            else
            {
                v[0] = i+1 ; 
                v[1] = j+1 ;  
                break ;
            }
       }

       return v ; 


    }
};
