class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0 ; 
        int n = arr.size() ;
        int r = n-k ;

        while(l < r)
        {
            int m = l + (r-l)/2 ; 
            
            if (x - arr[m] > arr[m+k] - x) l = m+1 ; 
            else r = m ;
        }

        vector <int> ans ; 
        int cnt = 0  ;
        for (int i = l ; cnt < k ; cnt++ , i++)
        {
            ans.push_back(arr[i]) ; 
        }

        return ans;  
    }
};