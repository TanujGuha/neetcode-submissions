/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0 ; 
        vector <pair<int,int>> vp ; 

        for (int i = 0 ; i < intervals.size() ; i++)
        {
            vp.push_back({intervals[i].start , 1}) ; 
            vp.push_back({intervals[i].end , -1}) ; 
        }

        sort(vp.begin() , vp.end()) ; 
        int m = 1 ;
        int c = 0 ;  

        for (int i = 0 ; i < vp.size() ; i++)
        {
            c += vp[i].second ; 
            m = max(c , m) ; 
        }

        return m ; 
    }
};
