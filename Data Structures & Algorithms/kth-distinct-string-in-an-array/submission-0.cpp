class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> counts;
        
        // Pass 1: Count frequency of each string
        for (const string& s : arr) {
            counts[s]++;
        }

        // Pass 2: Iterate through original array to preserve insertion order
        for (const string& s : arr) {
            if (counts[s] == 1) { // String is distinct
                k--;
                if (k == 0) {    // Found the k-th distinct string
                    return s;
                }
            }
        }

        // If fewer than k distinct strings exist
        return "";
    }
};