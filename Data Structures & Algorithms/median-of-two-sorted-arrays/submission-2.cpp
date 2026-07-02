class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> &a = nums1  ; 
        vector <int>&b = nums2 ; 

        int tot = a.size() + b.size() ; 

        int h = (tot + 1)/2 ;

        if (b.size() < a.size()) swap(a , b) ; 

        int l = 0 ; 
        int r = a.size() ; 


        while(l <= r)
        {
            int i = l + (r-l)/2 ; 
            int j = h - i ; 

            int al = i > 0 ? a[i-1] : INT_MIN ; 
            int ar = i < a.size() ? a[i] : INT_MAX ;
            int bl = j > 0 ? b[j-1] : INT_MIN ; 
            int br = j < b.size() ? b[j] :INT_MAX ;

            if(al <= br && bl <= ar) {
                if (tot%2 == 0) return (max(al,bl) + min(ar,br)) / 2.0 ; 
                else return max(al , bl) ; 
            }
            else
            {
                if (al > br)
                {
                    r = i - 1 ; 
                }
                else
                {
                    l = i + 1 ;
                }
            }
        }

        return -1 ;  
    }
};
