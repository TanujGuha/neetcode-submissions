class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
                    //  target_node  time
        vector <vector<pair<int,int>>> gr(n+1) ; 

        for (int i = 0 ; i < times.size() ; i++)
        {
            int from = times[i][0] ; 
            int to = times[i][1] ; 
            int t = times[i][2] ; 


            gr[from].push_back({to , t}) ; 
        }

        vector <int> ans(n+1 , INT_MAX) ; 
        ans[k] = 0 ;

        priority_queue <pair<int ,int> , vector<pair<int ,int>> , greater<pair<int ,int>>>  pq; 
        pq.push({0 , k}) ; 


        while(!pq.empty())
        {
            auto it = pq.top() ; 
            pq.pop();  

            int time = it.first ; 
            int ele = it.second ; 

            if (ans[ele] < time) continue ; 

            for (auto nbr : gr[ele])
            {
                int node = nbr.first ; 
                int tr = nbr.second ; 

                if (ans[node] >  time + tr)
                {
                    ans[node] = time + tr ; 
                    pq.push({ans[node] , node}) ; 
                }
            }
        }

        int cnt = 0 ; 
        for(int i = 1 ; i < n+1 ; i++)
        {
            if (ans[i] == INT_MAX)
            {
                return -1 ; 
            }
            cnt = max(cnt , ans[i]); 
        }

        return cnt ;   
        


    }
};