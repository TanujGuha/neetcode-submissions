class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        

        vector <int> dist(n , INT_MAX) ; 
        dist[src] = 0 ; 

        
        for (int i = 0 ; i <= k ; i++)
        {


            vector <int> temp = dist ; 
            for (auto e : flights)
            {
                int from = e[0] ; 
                int to = e[1] ; 
                int w = e[2] ; 

                if (dist[from] != INT_MAX && temp[to] > dist[from] + w)
                {
                    temp[to] = dist[from] + w ; 
                }
            }

            dist = temp ; 


        }


        return dist[dst] == INT_MAX ? -1 : dist[dst] ;
    }
};
