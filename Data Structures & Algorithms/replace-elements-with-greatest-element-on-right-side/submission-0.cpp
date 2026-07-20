class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size() ; 
        int prev = -1 ; 
        

        for (int i = n-1 ; i >= 0 ; i--)
        {
            int temp = arr[i] ;
            arr[i] = prev ; 
            prev = max(prev , temp) ; 
        }

        return arr ; 
    }
};