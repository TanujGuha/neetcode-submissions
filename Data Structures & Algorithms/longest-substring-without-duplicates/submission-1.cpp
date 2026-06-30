class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() ; 

        int left = 0 ; 
        int right = 1 ; 

        if (n == 1) return 1 ; 
        if (s == "") return 0 ; 
        int m = 1 ; 
        unordered_map <char,int> freq ; 
        freq[s[left]]++ ; 
        while(right < n)
        {
            freq[s[right]]++ ; 
            if (freq[s[right]] > 1) //  hit duplicate
            {
                while(s[left] != s[right])
                {
                    freq[s[left]]-- ; 
                    left++ ; 
                }
                freq[s[left]]-- ; 
                left++ ;
            }
            else
            {
                m = max(right - left + 1 , m) ; 
            }

            right++ ; 
        }

        return m ; 
    }
};
