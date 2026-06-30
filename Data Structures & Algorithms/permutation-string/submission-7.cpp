class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Fix 1: Handle length mismatch edge case safely
        if (s1.size() > s2.size()) return false;

        vector<int> f1(26, 0); 
        vector<int> f2(26, 0); 

        for (char ch : s1) f1[ch - 'a']++; 
        
        // Fix 2: Initialize f2 only up to s1.size()
        for (int i = 0; i < s1.size(); i++) f2[s2[i] - 'a']++; 

        int mat = 0; 
        for (int i = 0; i < 26; i++) {
            if (f1[i] == f2[i]) mat++; 
        }

        if (mat == 26) return true; 

        int l = 0; 
        for (int r = s1.size(); r < s2.size(); r++, l++) {
            int ch = s2[r] - 'a'; 
            f2[ch]++; 

            if (f2[ch] == f1[ch]) {
                mat++; 
            }
            // Fix 3: Adjust overshoot math
            else if (f2[ch] == f1[ch] + 1) {
                mat--; 
            }

            int go = s2[l] - 'a'; 
            f2[go]--;

            if (f2[go] == f1[go]) {
                mat++; 
            }
            // Fix 4: Adjust undershoot math
            else if (f2[go] == f1[go] - 1) {
                mat--; 
            }

            if (mat == 26) return true; 
        }

        return false; 
    }
};