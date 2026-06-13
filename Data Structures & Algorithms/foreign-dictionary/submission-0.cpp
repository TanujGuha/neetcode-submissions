#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size(); 
        vector<bool> exists(26, false); // Track letters that actually appear
        
        // Mark all present characters
        for (const auto& w : words) {
            for (char c : w) {
                exists[c - 'a'] = true;
            }
        }

        vector<vector<int>> v(26); 
        for (int i = 1; i < n; i++) {
            string w1 = words[i-1];
            string w2 = words[i];
            
            // Trap Check: If w1 is longer than w2 and w2 is a prefix of w1, it's invalid!
            if (w1.size() > w2.size() && w1.compare(0, w2.size(), w2) == 0) {
                return "";
            }

            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w2[j] != w1[j]) {
                    v[w1[j] - 'a'].push_back(w2[j] - 'a'); 
                    break; 
                }
            }
        }

        vector<int> id(26, 0); 
        for (int i = 0; i < 26; i++) {
            for (auto it : v[i]) {
                id[it]++; 
            }
        }

        queue<int> q; 
        // Fixed: Only push into the queue if the character actually exists in the words
        for (int i = 0; i < 26; i++) {
            if (exists[i] && id[i] == 0) {
                q.push(i); 
            }
        }

        vector<char> ans; 
        while (!q.empty()) {
            int it = q.front(); 
            q.pop(); 

            ans.push_back(it);

            for (auto itt : v[it]) {
                id[itt]--; 
                if (id[itt] == 0) {
                    q.push(itt); 
                }
            }
        }

        // Count unique characters
        int unique_count = 0;
        for (int i = 0; i < 26; i++) {
            if (exists[i]) unique_count++;
        }

        string del = "";
        // If our processed topological sort length matches the number of unique letters, no cycles exist!
        if (ans.size() == unique_count) { 
            for (auto it : ans) {
                del += ('a' + it); 
            }
        }

        return del; 
    }
};