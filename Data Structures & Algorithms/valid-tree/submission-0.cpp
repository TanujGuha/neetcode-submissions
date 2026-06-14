class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() < n-1 || edges.size() > n-1)
        {
            return false ; 
        }

        vector <int> rank(n , 0) ;
        vector <int> parent(n) ;

        for (int i = 0 ; i < n ; i++)
        {
            parent[i] = i ; 
        }


        for (auto it: edges)
        {
            int u = it[0] ; 
            int v = it[1] ; 

            if (ur(u , v , parent , rank) == false)
            {
                return false ; 
            }
        }
        return true ; 
    }


    int fP(int u , vector <int> &parent) 
    {
        if (u == parent[u])
        {
            return u ;
        }
        return parent[u] = fP(parent[u] , parent) ; 
    }


    bool ur(int u ,int v , vector <int> &parent , vector <int> &rank)
    {
        int up = fP(u , parent) ; 
        int vp = fP(v , parent) ; 

        if (up == vp)
        {
            return false ; 
        }

        int ru = rank[up] ; 
        int rv = rank[vp] ; 

        if(ru < rv)
        {
            parent[up] = vp ;  
        }
        else if(ru > rv)
        {
            parent[vp] = up ; 
        }
        else
        {
            parent[up] = vp ; 
            rank[vp]++ ; 
        }
        return true ; 
    }
};
