class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];

        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin() , envelopes.end() , cmp) ; 

        vector <int> tail ; 

        for (auto e : envelopes)
        {
            int h = e[1] ; 
            auto it = lower_bound(tail.begin() , tail.end() , h) ;
            if (it == tail.end())
            {
                tail.push_back(h) ; 
            }
            else
            {
                *it = h ; 
            }
        }

        return tail.size() ;
    }
};