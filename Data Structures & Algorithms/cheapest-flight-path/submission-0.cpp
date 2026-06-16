class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector <vector <int>> dist(n , vector <int>(k+2 , INT_MAX)) ; 

        // if dist[i][j] = x 
        // we reach from source to i at a minimum cost of x
        // using exactly j stops


        dist[src][0] = 0 ; 
        vector <vector<pair<int,int>>> gr(n) ; 
        for(auto it : flights)
        {
            int start = it[0] ; 
            int end   = it[1] ;     
            int cst   = it[2] ; 

            gr[start].push_back({end , cst}) ; 
        }
                            //    cost stops  desti
        priority_queue < pair<pair<int ,int > , int> , vector <pair<pair<int ,int > , int>> , greater<pair<pair<int ,int > , int>> > pq ;
        pq.push({{0 , 0} , src})  ; 


        while(!pq.empty())
        {
            auto it = pq.top() ;
            pq.pop() ; 

            int cost = it.first.first ; 
            int stops = it.first.second ; 
            int lay = it.second ;

            if (lay == dst) return cost ; 
            if (stops > k) continue; 

            for (auto nbr : gr[lay])
            {
                int cs = nbr.second ; 
                int dest = nbr.first ; 

                if (stops + 1 <= k+2 && dist[dest][stops+1] > cost + cs)
                {
                    dist[dest][stops+1] = cost + cs ; 
                    pq.push({{cost + cs , stops+1} , dest}) ; 
                }
            }

        }

        int mn = INT_MAX ; 

        for (int j = 0 ; j < k+2 ; j++)
        {
            mn = min(dist[dst][j] , mn) ;
        }

        if (mn == INT_MAX)
        {
            return -1 ; 
        }
        else
        {
            return mn ; 
        }
    }
};
