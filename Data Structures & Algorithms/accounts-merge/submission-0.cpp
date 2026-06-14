#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size(); 
        vector<int> rank(n, 0);
        vector<int> parent(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i; 
        }

        map<string, int> mp;

        for(int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.count(accounts[i][j]) > 0) {
                    uni(i, mp[accounts[i][j]], parent, rank); 
                }
                else {
                    mp[accounts[i][j]] = i; 
                }
            }
        }

        vector<vector<string>> ans(n); 

        // Fixed: Switched to a linear O(M) range loop. 
        // Bonus: Because 'map' is sorted, emails are inserted alphabetically!
        for (auto& [email, id] : mp) {
            ans[fP(id, parent)].push_back(email); 
        }

        vector<vector<string>> fa; 
        for (int i = 0; i < n; i++) {
            if (!ans[i].empty()) {
                vector<string> temp;
                temp.push_back(accounts[i][0]); // Step 1: Add the owner's name
                
                for (int j = 0; j < ans[i].size(); j++) {
                    temp.push_back(ans[i][j]);  // Step 2: Add sorted emails
                }
                fa.push_back(temp); // Fixed: Safely pushing the assembled vector
            }
        }

        return fa; 
    }

    int fP(int u, vector<int> &parent) {
        if(u == parent[u]) {
            return u; 
        }
        return parent[u] = fP(parent[u], parent);
    }

    void uni(int u, int v, vector<int> &parent, vector<int> &rank) {
        int up = fP(u, parent); 
        int vp = fP(v, parent); 

        if (up == vp) {
            return; 
        }

        int ru = rank[up]; 
        int rv = rank[vp]; 

        if(ru < rv) {
            parent[up] = vp; 
        }
        else if(ru > rv) {
            parent[vp] = up; 
        }
        else {
            parent[up] = vp; 
            rank[vp]++; 
        }
    }
};