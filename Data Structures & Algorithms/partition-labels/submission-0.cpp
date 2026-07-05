class Solution {
public:
    vector<int> partitionLabels(string st) {
        // Initialize with -1 to properly track if a character has been seen
        vector<int> first(26, -1); 
        vector<int> last(26, -1); 

        for (int i = 0; i < st.size(); i++) {
            int idx = st[i] - 'a';
            if (first[idx] != -1) { // Fixed: explicitly check against -1
                last[idx] = i; 
            } else {
                first[idx] = i; 
                last[idx] = i; 
            }
        }

        vector<vector<int>> intervals; 
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1) { // Fixed: explicitly check against -1 so index 0 isn't skipped
                intervals.push_back({first[i], last[i]}); 
            }
        }

        // Sort intervals by their start times
        sort(intervals.begin(), intervals.end()); 
        
        vector<int> ans; 
        int s = intervals[0][0];
        int e = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            // Overlap check
            if ((s <= intervals[i][1]) && (intervals[i][0] <= e)) {
                s = min(s, intervals[i][0]); 
                e = max(e, intervals[i][1]); 
            } else {
                // Fixed: Push the LENGTH of the partition (end - start + 1)
                ans.push_back(e - s + 1); 
                s = intervals[i][0]; 
                e = intervals[i][1];
            }
        }
        
        // Fixed: Don't forget to push the very last partition length!
        ans.push_back(e - s + 1); 
        
        return ans;  
    }
};