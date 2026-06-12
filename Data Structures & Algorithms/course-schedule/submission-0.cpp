#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int e = pre.size();
        vector<int> ind(numCourses, 0); 
        vector<vector<int>> lis(numCourses); 
        unordered_set<int> visi; 

        for (int i = 0; i < e; i++) {
            lis[pre[i][1]].push_back(pre[i][0]);
            ind[pre[i][0]]++; 
        } 

        queue<int> q; 
        for (int i = 0; i < numCourses; i++) {
            if (ind[i] == 0) {
                q.push(i); 
                visi.insert(i);
            }
        }

        // Track how many courses are successfully processed
        int courses_processed = 0;

        // Pass visi by reference, and let bfs count our popped elements
        bfs(q, lis, q.size(), ind, visi, courses_processed);

        // If we processed all courses, there is no deadlocked cycle!
        return courses_processed == numCourses;
    }

    // Fixed: Passed visi by reference (&visi) and added processed tracking counter
    void bfs(queue<int> &q, vector<vector<int>> &lis, int l, vector<int> &ind, unordered_set<int> &visi, int &courses_processed) {
        if (q.empty()) {
            return; 
        }

        int na = 0; 
        while (l--) {   
            auto it = q.front(); 
            q.pop(); 
            courses_processed++; // Increment every time a course is successfully cleared

            for (auto i : lis[it]) {
                ind[i]--; 
                
                // If all prerequisites are cleared and we haven't visited it yet
                if (ind[i] == 0 && visi.count(i) == 0) {
                    na++; 
                    q.push(i); 
                    visi.insert(i);
                }
            }
        }

        bfs(q, lis, na, ind, visi, courses_processed); 
    }
};