class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector <vector<pair <int,double>>> gr(n) ; 

        for (int i = 0 ; i < edges.size() ; i++)
        {
            auto it = edges[i] ; 
            int a  = it[0] ; 
            int b = it[1] ; 

            double prob = succProb[i] ; 

            gr[a].push_back({b , prob}) ;
            gr[b].push_back({a , prob}) ;
        }


        double tp = 1.0 ;       
                //           the Prob the Node 
        priority_queue <pair <double,int>> pq ;
        pq.push( {1 , start} ) ; 
        vector <double> ans (n+1 , 0.0 ) ; 
        ans[start] = 1.0  ; 

        while(!pq.empty())
        {
            auto it = pq.top() ; 
            pq.pop() ; 

            double prb = it.first ; 
            int ele = it.second ; 

            if (ans[ele] > prb) continue ; 

            for (auto nei : gr[ele])
            {
                int i = nei.first ; 
                double p = nei.second ; 

                if (ans[i] < prb*p)
                {
                    ans[i] = prb*p ; 
                    pq.push({ans[i] , i}) ; 
                }
            }
        }


        return ans[end] ;

    }
};