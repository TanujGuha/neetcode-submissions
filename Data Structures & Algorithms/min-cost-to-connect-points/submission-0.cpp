class Solution {
public:

    using pii = pair <int,int> ;
    int fP(int u , vector <int>&parent)
    {
        if (u == parent[u])
        {
            return u ; 
        }

        return parent[u] = fP(parent[u] , parent) ; 
    }



    void ur(int u , int v , vector <int> &parent , vector <int> &rank)
    {
        int up = fP(u , parent) ; 
        int vp = fP(v , parent) ; 
        
        if (up == vp)
        {
            return ; 
        }


        int ru = rank[up] ; 
        int rv = rank[vp] ; 

        if (ru < rv){
            parent[up] = vp ; 
        }
        else if (ru > rv)
        {
            parent[vp] = up ; 
        }
        else
        {
            parent[up] = vp ; 
            rank[vp]++ ;
        }

        return ; 
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 

        vector <int> parent(n) ; 
        vector <int> rank(n , 0) ; 

        for(int i = 0 ; i < n ; i++)
        {
            parent[i] = i ; 
        }


        priority_queue < pair<int ,pii> , vector <pair<int ,pii>> , greater <pair<int ,pii>> > pq ; 

        for (int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ;j++) // core optimization
            {
                if (i == j) continue ; 
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) ; 
                pq.push( {d ,{i,j}} ) ;
            }
        }


        int wt = 0 ;
        while(!pq.empty())
        {
            auto it = pq.top() ; 
            pq.pop() ; 
            int w = it.first ; 
            int u = it.second.first ; 
            int v = it.second.second ; 

            if (fP(u , parent) == fP(v , parent))
            {
                continue ;
            }

            ur(u , v , parent , rank) ; 
            wt += w ;
        }


        return wt ; 

    }
};
